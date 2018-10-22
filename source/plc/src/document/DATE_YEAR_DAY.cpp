﻿// This file was generated using Parlex's cpp_generator

#include "DATE_YEAR_DAY.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
plc::DATE_YEAR_DAY plc::DATE_YEAR_DAY::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2D_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[7], w);
	return DATE_YEAR_DAY(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6, v7);
}


parlex::detail::acceptor const & plc::DATE_YEAR_DAY::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DATE_YEAR_DAY));
	return result;
}
