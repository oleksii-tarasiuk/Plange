﻿// This file was generated using Parlex's cpp_generator

#include "USING.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "BLOCK.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::USING plc::USING::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_using_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<val<BLOCK>>::build(&*children[8], w);
	return USING(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6, v7, v8);
}


parlex::detail::acceptor const & plc::USING::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().USING));
	return result;
}
