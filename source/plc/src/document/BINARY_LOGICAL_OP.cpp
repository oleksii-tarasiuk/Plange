// This file was generated using Parlex's cpp_generator

#include "BINARY_LOGICAL_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "AND.hpp"
#include "IFF.hpp"
#include "IMPLICATION.hpp"
#include "MAPS_TO.hpp"
#include "NAND.hpp"
#include "NOR.hpp"
#include "OR.hpp"
#include "XOR.hpp"

#include "BINARY_LOGICAL_OP.hpp"

namespace plc {

BINARY_LOGICAL_OP BINARY_LOGICAL_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().BINARY_LOGICAL_OP.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BINARY_LOGICAL_OP(parlex::detail::document::element<BINARY_LOGICAL_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::BINARY_LOGICAL_OP::recognizer() {
	return plange_grammar::get().BINARY_LOGICAL_OP.get_recognizer();
}
