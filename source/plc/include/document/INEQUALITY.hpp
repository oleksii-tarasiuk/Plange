﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INEQUALITY_HPP
#define INCLUDED_INEQUALITY_HPP

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

struct INEQUALITY {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x890xA0_t>,
		parlex::detail::document::text<literal_0x2F0x3D_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit INEQUALITY
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x890xA0_t>,
	parlex::detail::document::text<literal_0x2F0x3D_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	INEQUALITY(INEQUALITY const & other) = default;
	static INEQUALITY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_INEQUALITY_HPP
