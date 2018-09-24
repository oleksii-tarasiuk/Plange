﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EQUALITY_CHAIN_HPP
#define INCLUDED_EQUALITY_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EQUALITY_CHAIN_LOOP;
struct EXPRESSION;
struct IC;

struct EQUALITY_CHAIN {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> expression;
	
	std::vector<val<IC>> field_1;
	
	val<EQUALITY_CHAIN_LOOP> equality_chain_loop;
	


	explicit EQUALITY_CHAIN
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> && expression, std::vector<val<IC>> && field_1, val<EQUALITY_CHAIN_LOOP> && equality_chain_loop)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), expression(std::move(expression)), field_1(std::move(field_1)), equality_chain_loop(std::move(equality_chain_loop)) {}

	EQUALITY_CHAIN(EQUALITY_CHAIN const & other) = default;
	EQUALITY_CHAIN(EQUALITY_CHAIN && move) = default;

	static EQUALITY_CHAIN build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_EQUALITY_CHAIN_HPP
