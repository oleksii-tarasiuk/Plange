﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IMPLICATION_ASSIGNMENT_HPP
#define INCLUDED_IMPLICATION_ASSIGNMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct IMPLICATION_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x870x92_t>,
		parlex::detail::document::text<literal_0x3D0x3E_t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	
	std::vector<val<IC>> field_5;
	
	val<EXPRESSION> field_6;
	


	explicit IMPLICATION_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x870x92_t>,
	parlex::detail::document::text<literal_0x3D0x3E_t>
> const & field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_4, std::vector<val<IC>> const & field_5, val<EXPRESSION> const & field_6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6) {}

	IMPLICATION_ASSIGNMENT(IMPLICATION_ASSIGNMENT const & other) = default;
	static IMPLICATION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_IMPLICATION_ASSIGNMENT_HPP
