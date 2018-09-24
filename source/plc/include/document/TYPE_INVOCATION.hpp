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

struct ARGUMENT;
struct ARGUMENT_PACK;
struct EXPRESSION;
struct IC;

struct TYPE_INVOCATION {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		struct argsHead_t {
			std::vector<val<IC>> field_1;
			
			std::variant<
				val<ARGUMENT>,
				val<ARGUMENT_PACK>
			> field_2;
			
		
		
			explicit argsHead_t
				(std::vector<val<IC>> && field_1, std::variant<
			val<ARGUMENT>,
			val<ARGUMENT_PACK>
		> && field_2)
				: field_1(std::move(field_1)), field_2(std::move(field_2)) {}
		
			argsHead_t(argsHead_t const & other) = default;
			argsHead_t(argsHead_t && move) = default;
		
			static argsHead_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		struct argsTail_t {
			struct field_2_t {
				std::vector<val<IC>> field_1;
				
				std::variant<
					val<ARGUMENT>,
					val<ARGUMENT_PACK>
				> field_2;
				
			
			
				explicit field_2_t
					(std::vector<val<IC>> && field_1, std::variant<
				val<ARGUMENT>,
				val<ARGUMENT_PACK>
			> && field_2)
					: field_1(std::move(field_1)), field_2(std::move(field_2)) {}
			
				field_2_t(field_2_t const & other) = default;
				field_2_t(field_2_t && move) = default;
			
				static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
			};
		
			std::vector<val<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C_t> dont_care1;
			
			std::optional<field_2_t> field_2;
			
		
		
			explicit argsTail_t
				(std::vector<val<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dont_care1, std::optional<field_2_t> && field_2)
				: field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)) {}
		
			argsTail_t(argsTail_t const & other) = default;
			argsTail_t(argsTail_t && move) = default;
		
			static argsTail_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		parlex::detail::document::text<literal_0x3C_t> dont_care0;
		
		std::optional<argsHead_t> argsHead;
		
		std::vector<argsTail_t> argsTail;
		
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x3E_t> dont_care4;
		
	
	
		explicit field_1_t
			(parlex::detail::document::text<literal_0x3C_t> && dont_care0, std::optional<argsHead_t> && argsHead, std::vector<argsTail_t> && argsTail, std::vector<val<IC>> && field_1, parlex::detail::document::text<literal_0x3E_t> && dont_care4)
			: dont_care0(std::move(dont_care0)), argsHead(std::move(argsHead)), argsTail(std::move(argsTail)), field_1(std::move(field_1)), dont_care4(std::move(dont_care4)) {}
	
		field_1_t(field_1_t const & other) = default;
		field_1_t(field_1_t && move) = default;
	
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<EXPRESSION> target;
	
	field_1_t field_1;
	


	explicit TYPE_INVOCATION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> && target, field_1_t && field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), target(std::move(target)), field_1(std::move(field_1)) {}

	TYPE_INVOCATION(TYPE_INVOCATION const & other) = default;
	TYPE_INVOCATION(TYPE_INVOCATION && move) = default;

	static TYPE_INVOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_INVOCATION_HPP
