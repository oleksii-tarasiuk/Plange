#include "Do.hpp"


Do::Do() {}


Do::~Do() {}

std::unique_ptr<Statement> Do::Build(parlex::match const& m, parlex::abstract_syntax_graph const& asg) {
	throw std::logic_error("Not implemented.");
}