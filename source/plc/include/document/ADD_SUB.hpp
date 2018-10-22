﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ADD_SUB_HPP
#define INCLUDED_ADD_SUB_HPP

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

struct ADD_SUB {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xC20xB1_t>,
		parlex::detail::document::text<literal_0x2B0x2D_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit ADD_SUB
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xC20xB1_t>,
	parlex::detail::document::text<literal_0x2B0x2D_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	ADD_SUB(ADD_SUB const & other) = default;
	static ADD_SUB build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ADD_SUB_HPP
