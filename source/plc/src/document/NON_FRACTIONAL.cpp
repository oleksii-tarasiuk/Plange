﻿// This file was generated using Parlex's cpp_generator

#include "NON_FRACTIONAL.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "NON_NEG_NON_FRACTIONAL.hpp"

plc::NON_FRACTIONAL plc::NON_FRACTIONAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<parlex::detail::document::text<literal_0x2D_t>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<NON_NEG_NON_FRACTIONAL>>::build(&*children[1], w);
	return NON_FRACTIONAL(n.document_position, n.consumed_character_count, v0, v1);
}


parlex::detail::acceptor const & plc::NON_FRACTIONAL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NON_FRACTIONAL));
	return result;
}
