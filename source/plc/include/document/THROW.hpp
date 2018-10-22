﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_THROW_HPP
#define INCLUDED_THROW_HPP

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

struct THROW {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x5B_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> field_3;
		
		std::vector<val<IC>> field_4;
		
		parlex::detail::document::text<literal_0x5D_t> dont_care5;
		
	
	
		explicit field_1_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x5B_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3, std::vector<val<IC>> const & field_4, parlex::detail::document::text<literal_0x5D_t> const & dont_care5)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3), field_4(field_4), dont_care5(dont_care5) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_2_t {
		std::vector<val<IC>> field_1;
		
		val<EXPRESSION> field_2;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2)
			: field_1(field_1), field_2(field_2) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_throw_t> dont_care0;
	
	std::optional<field_1_t> field_1;
	
	std::optional<field_2_t> field_2;
	


	explicit THROW
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_throw_t> const & dont_care0, std::optional<field_1_t> const & field_1, std::optional<field_2_t> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	THROW(THROW const & other) = default;
	static THROW build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_THROW_HPP
