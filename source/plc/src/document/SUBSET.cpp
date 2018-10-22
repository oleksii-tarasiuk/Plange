﻿// This file was generated using Parlex's cpp_generator

#include "SUBSET.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "SUBSET_NODE.hpp"

plc::SUBSET plc::SUBSET::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<SUBSET_NODE>>::build(&*children[2], w);
	return SUBSET(n.document_position, n.consumed_character_count, v0, v1, v2);
}


parlex::detail::acceptor const & plc::SUBSET::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SUBSET));
	return result;
}
