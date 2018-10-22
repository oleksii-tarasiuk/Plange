﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_COMPLEMENT_HPP
#define INCLUDED_COMPLEMENT_HPP

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

struct COMPLEMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0xE10xB60x9C_t> dont_care2;
	


	explicit COMPLEMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0xE10xB60x9C_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2) {}

	COMPLEMENT(COMPLEMENT const & other) = default;
	static COMPLEMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_COMPLEMENT_HPP
