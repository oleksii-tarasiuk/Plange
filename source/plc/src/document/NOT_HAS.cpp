// This file was generated using Parlex's cpp_generator

#include "NOT_HAS.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::NOT_HAS plc::NOT_HAS::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().NOT_HAS.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880x8C_t>,
		parlex::detail::document::text<literal_0x2Fhas_t>
	>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[4], w);
	return NOT_HAS(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}


parlex::detail::recognizer const & plc::NOT_HAS::recognizer() {
	return plange_grammar::get().NOT_HAS.get_recognizer();
}
