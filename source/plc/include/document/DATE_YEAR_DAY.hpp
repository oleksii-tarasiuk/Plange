﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DATE_YEAR_DAY_HPP
#define INCLUDED_DATE_YEAR_DAY_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DATE_YEAR_DAY {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_1;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_2;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_3;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_4;
	
	parlex::detail::document::text<literal_0x2D_t> dont_care4;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_5;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_6;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_7;
	


	explicit DATE_YEAR_DAY
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_1, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_2, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_3, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_4, parlex::detail::document::text<literal_0x2D_t> const & dont_care4, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_5, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_6, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_7)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), dont_care4(dont_care4), field_5(field_5), field_6(field_6), field_7(field_7) {}

	DATE_YEAR_DAY(DATE_YEAR_DAY const & other) = default;
	static DATE_YEAR_DAY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_DATE_YEAR_DAY_HPP
