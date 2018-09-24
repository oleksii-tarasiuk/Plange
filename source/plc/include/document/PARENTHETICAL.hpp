﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARENTHETICAL_HPP
#define INCLUDED_PARENTHETICAL_HPP

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

struct PARENTHETICAL {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x28_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	
	std::vector<val<IC>> field_3;
	
	parlex::detail::document::text<literal_0x29_t> dont_care4;
	


	explicit PARENTHETICAL
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x28_t> && dont_care0, std::vector<val<IC>> && field_1, val<EXPRESSION> && field_2, std::vector<val<IC>> && field_3, parlex::detail::document::text<literal_0x29_t> && dont_care4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), dont_care4(std::move(dont_care4)) {}

	PARENTHETICAL(PARENTHETICAL const & other) = default;
	PARENTHETICAL(PARENTHETICAL && move) = default;

	static PARENTHETICAL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_PARENTHETICAL_HPP
