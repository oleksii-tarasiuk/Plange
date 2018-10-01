﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_INVOCATION_HPP
#define INCLUDED_TYPE_INVOCATION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct STANDARD_ARGUMENTS;

struct TYPE_INVOCATION {
	int32_t document_position, consumed_character_count;

	struct arguments_t {
		val<STANDARD_ARGUMENTS> standard_arguments;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit arguments_t
			(val<STANDARD_ARGUMENTS> && standard_arguments, std::vector<val<IC>> && ic)
			: standard_arguments(std::move(standard_arguments)), ic(std::move(ic)) {}
	
		arguments_t(arguments_t const & other) = default;
		arguments_t(arguments_t && move) = default;
	
		static arguments_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x3C_t> dont_care0;
	
	std::vector<val<IC>> ic;
	
	std::optional<arguments_t> arguments;
	
	parlex::detail::document::text<literal_0x3E_t> dont_care3;
	


	explicit TYPE_INVOCATION
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x3C_t> && dont_care0, std::vector<val<IC>> && ic, std::optional<arguments_t> && arguments, parlex::detail::document::text<literal_0x3E_t> && dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), ic(std::move(ic)), arguments(std::move(arguments)), dont_care3(std::move(dont_care3)) {}

	TYPE_INVOCATION(TYPE_INVOCATION const & other) = default;
	TYPE_INVOCATION(TYPE_INVOCATION && move) = default;

	static TYPE_INVOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_INVOCATION_HPP
