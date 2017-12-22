// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_THROWING.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "ARRAY.hpp"
#include "FUNCTION_MODIFIER_2.hpp"
#include "IC.hpp"
#include "ICR.hpp"

plc::FUNCTION_MODIFIER_THROWING::field_1_t_1_t plc::FUNCTION_MODIFIER_THROWING::field_1_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<ARRAY>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::FUNCTION_MODIFIER_THROWING::field_2_t_1_t plc::FUNCTION_MODIFIER_THROWING::field_2_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<ICR>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<FUNCTION_MODIFIER_2>>::build(&*children[1], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1));
}

plc::FUNCTION_MODIFIER_THROWING plc::FUNCTION_MODIFIER_THROWING::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().FUNCTION_MODIFIER_THROWING.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_throwing_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::optional<field_2_t_1_t>>::build(&*children[2], w);
	return FUNCTION_MODIFIER_THROWING(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::detail::recognizer const & plc::FUNCTION_MODIFIER_THROWING::recognizer() {
	return plange_grammar::get().FUNCTION_MODIFIER_THROWING.get_recognizer();
}
