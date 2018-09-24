﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RADICAL_ASSIGNMENT_HPP
#define INCLUDED_RADICAL_ASSIGNMENT_HPP

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

struct RADICAL_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x880x9A_t>,
		parlex::detail::document::text<literal_sqrt_t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	


	explicit RADICAL_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> && field_1, std::vector<val<IC>> && field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x880x9A_t>,
	parlex::detail::document::text<literal_sqrt_t>
> && field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> && field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	RADICAL_ASSIGNMENT(RADICAL_ASSIGNMENT const & other) = default;
	RADICAL_ASSIGNMENT(RADICAL_ASSIGNMENT && move) = default;

	static RADICAL_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_RADICAL_ASSIGNMENT_HPP
