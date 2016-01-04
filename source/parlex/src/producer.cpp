#include <cassert>
#include <mutex>

#include "parlex/details/job.hpp"
#include "parlex/details/subjob.hpp"
#include "parlex/parser.hpp"
#include "parlex/details/producer.hpp"
#include "parlex/details/subjob.hpp"
#include "parlex/details/logging.hpp"

namespace parlex {
namespace details {

producer::producer(job & owner, recognizer const & r, size_t const documentPosition) :
	owner(owner),
	r(r),
	documentPosition(documentPosition),
	completed(false) {}


void producer::add_subscription(context_ref const & c, size_t nextDfaState) {
	{
		std::unique_lock<std::mutex> lock(mutex);
		consumers.emplace_back(c, nextDfaState);
	}  //release the lock
	do_events();
}

void producer::do_events() {
	auto & parser = owner.owner;
	std::unique_lock<std::mutex> lock(mutex);
	for (subscription & subscription : consumers) {
		subjob & targetSubjob = subscription.c.owner();

		while (subscription.next_index < match_to_permutations.size()) {
			auto match = matches[subscription.next_index];
			subscription.next_index++;
			context_ref next = targetSubjob.construct_stepped_context(subscription.c, match);
			parser.schedule(next, subscription.next_dfa_state);
		};
	}
}

void producer::enque_permutation(size_t consumedCharacterCount, permutation const & p) {
	bool newMatch = false;
	{
		std::unique_lock<std::mutex> lock(mutex);
		match m(match_class(r, documentPosition), consumedCharacterCount);
		if (!match_to_permutations.count(m)) {
			match_to_permutations[m] = std::set<permutation>();
			matches.push_back(m);
			newMatch = true;
		}
		match_to_permutations[m].insert(p);
	}
	if (newMatch) {
		do_events();
	}
}

void producer::terminate() {
	//no lock on "mutex" is to be done because this method is logically exclusive
	for (subscription & subscription : consumers) {
		subjob & targetSubjob = subscription.c.owner();
		targetSubjob.end_dependency();
	}
	owner.producer_terminated(*this);
}
}
}
