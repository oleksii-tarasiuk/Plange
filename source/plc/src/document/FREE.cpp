// This file was generated using Parlex's cpp_generator

#include "FREE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::FREE plc::FREE::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().FREE.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_free_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	return FREE(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::detail::recognizer const & plc::FREE::recognizer() {
	return plange_grammar::get().FREE.get_recognizer();
}
