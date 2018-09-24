﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_LESSER_CHAIN_LOOP_HPP
#define INCLUDED_LESSER_CHAIN_LOOP_HPP

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
struct LESSER_CHAIN_LOOP;

struct LESSER_CHAIN_LOOP {
	int32_t document_position, consumed_character_count;

	struct field_4_t {
		std::vector<val<IC>> field_1;
		
		val<LESSER_CHAIN_LOOP> field_2;
		
	
	
		explicit field_4_t
			(std::vector<val<IC>> && field_1, val<LESSER_CHAIN_LOOP> && field_2)
			: field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_4_t(field_4_t const & other) = default;
		field_4_t(field_4_t && move) = default;
	
		static field_4_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_0x3D_t>,
		parlex::detail::document::text<literal_0x3C_t>,
		parlex::detail::document::text<literal_0x3D0x3C_t>,
		parlex::detail::document::text<literal_0xE20x890xA4_t>
	> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> field_3;
	
	std::optional<field_4_t> field_4;
	


	explicit LESSER_CHAIN_LOOP
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0x3D_t>,
	parlex::detail::document::text<literal_0x3C_t>,
	parlex::detail::document::text<literal_0x3D0x3C_t>,
	parlex::detail::document::text<literal_0xE20x890xA4_t>
> && field_1, std::vector<val<IC>> && field_2, val<EXPRESSION> && field_3, std::optional<field_4_t> && field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	LESSER_CHAIN_LOOP(LESSER_CHAIN_LOOP const & other) = default;
	LESSER_CHAIN_LOOP(LESSER_CHAIN_LOOP && move) = default;

	static LESSER_CHAIN_LOOP build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_LESSER_CHAIN_LOOP_HPP
