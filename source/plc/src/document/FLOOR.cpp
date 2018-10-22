﻿// This file was generated using Parlex's cpp_generator

#include "FLOOR.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

#include "FLOOR.hpp"

namespace plc {

FLOOR FLOOR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FLOOR(parlex::detail::document::element<FLOOR_base>::build(b, w));
}

} // namespace plc
plc::FLOOR1_t plc::FLOOR1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8C0x8A_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8C0x8B_t>>::build(&*children[4], w);
	return FLOOR1_t(v0, v1, v2, v3, v4);
}

plc::FLOOR2_t plc::FLOOR2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C__t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal__0x7C_t>>::build(&*children[4], w);
	return FLOOR2_t(v0, v1, v2, v3, v4);
}


parlex::detail::acceptor const & plc::FLOOR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FLOOR));
	return result;
}
