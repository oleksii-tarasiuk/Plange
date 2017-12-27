// This file was generated using Parlex's cpp_generator

#include "NON_FRACTIONAL.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "NON_NEG_NON_FRACTIONAL.hpp"

plc::NON_FRACTIONAL plc::NON_FRACTIONAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = state_machine().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<parlex::detail::document::text<literal_0x2D_t>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<NON_NEG_NON_FRACTIONAL>>::build(&*children[1], w);
	return NON_FRACTIONAL(std::move(v0), std::move(v1));
}


parlex::detail::state_machine const & plc::NON_FRACTIONAL::state_machine() {
	static auto const & result = *static_cast<parlex::detail::state_machine const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NON_FRACTIONAL));
	return result;
}
