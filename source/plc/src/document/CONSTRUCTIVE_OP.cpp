// This file was generated using Parlex's cpp_generator

#include "CONSTRUCTIVE_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "COMPOSITION.hpp"
#include "COMPOUND.hpp"
#include "NULL_COALESCE.hpp"
#include "PREPEND.hpp"

#include "CONSTRUCTIVE_OP.hpp"

namespace plc {

CONSTRUCTIVE_OP CONSTRUCTIVE_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().CONSTRUCTIVE_OP.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return CONSTRUCTIVE_OP(parlex::detail::document::element<CONSTRUCTIVE_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::CONSTRUCTIVE_OP::recognizer() {
	return plange_grammar::get().CONSTRUCTIVE_OP.get_recognizer();
}
