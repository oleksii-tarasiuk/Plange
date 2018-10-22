﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BIT_XOR_HPP
#define INCLUDED_BIT_XOR_HPP

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

struct BIT_XOR {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x5E0x5E_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit BIT_XOR
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x5E0x5E_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	BIT_XOR(BIT_XOR const & other) = default;
	static BIT_XOR build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_BIT_XOR_HPP
