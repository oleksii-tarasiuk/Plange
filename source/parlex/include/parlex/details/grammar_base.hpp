#ifndef GRAMMAR_BASE_HPP
#define GRAMMAR_BASE_HPP

#include <map>

#include "parlex/precedence_collection.hpp"

#include "parlex/details/state_machine_base.hpp"
#include "parlex/details/string_terminal.hpp"

namespace parlex {
namespace details {

class builtins_t;

class grammar_base {
public:
	virtual state_machine_base const& get_main_state_machine() const = 0;
	virtual std::map<std::string, state_machine_base const *> get_state_machines() const = 0;
	virtual state_machine_base const& get_state_machine(std::string const & id) const = 0;
	virtual string_terminal const& get_literal(std::string const & id) const = 0;
	virtual bool test_precedence(state_machine_base const & productionA, state_machine_base const & productionB) const = 0;
	virtual precedence_collection get_precedences() const = 0;
protected:
	~grammar_base() = default;
	grammar_base() = default;
	grammar_base(grammar_base const & other) = default;
};

}
} // namespace parlex

#endif //GRAMMAR_BASE_HPP