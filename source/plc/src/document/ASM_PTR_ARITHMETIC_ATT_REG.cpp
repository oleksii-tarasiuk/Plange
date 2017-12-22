// This file was generated using Parlex's cpp_generator

#include "ASM_PTR_ARITHMETIC_ATT_REG.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "ASM_IDENTIFIER.hpp"
#include "NON_NEG_NON_FRACTIONAL.hpp"

plc::ASM_PTR_ARITHMETIC_ATT_REG::field_2_t_1_t::field_1_t_1_t plc::ASM_PTR_ARITHMETIC_ATT_REG::field_2_t_1_t::field_1_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<NON_NEG_NON_FRACTIONAL>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::ASM_PTR_ARITHMETIC_ATT_REG::field_2_t_1_t plc::ASM_PTR_ARITHMETIC_ATT_REG::field_2_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<ASM_IDENTIFIER>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[2], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::ASM_PTR_ARITHMETIC_ATT_REG plc::ASM_PTR_ARITHMETIC_ATT_REG::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ASM_PTR_ARITHMETIC_ATT_REG.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::optional<erased<ASM_IDENTIFIER>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::optional<field_2_t_1_t>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[3], w);
	return ASM_PTR_ARITHMETIC_ATT_REG(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}


parlex::detail::recognizer const & plc::ASM_PTR_ARITHMETIC_ATT_REG::recognizer() {
	return plange_grammar::get().ASM_PTR_ARITHMETIC_ATT_REG.get_recognizer();
}
