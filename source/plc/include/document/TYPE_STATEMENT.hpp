﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_STATEMENT_HPP
#define INCLUDED_TYPE_STATEMENT_HPP

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
struct STATEMENT;
struct TYPE_SCOPE_TYPE_CONSTRAINT;
struct VISIBILITY_MODIFIER;

struct TYPE_STATEMENT1_t {
	val<VISIBILITY_MODIFIER> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x3A_t> dont_care2;
	


	explicit TYPE_STATEMENT1_t
		(val<VISIBILITY_MODIFIER> && field_1, std::vector<val<IC>> && field_2, parlex::detail::document::text<literal_0x3A_t> && dont_care2)
		: field_1(std::move(field_1)), field_2(std::move(field_2)), dont_care2(std::move(dont_care2)) {}

	TYPE_STATEMENT1_t(TYPE_STATEMENT1_t const & other) = default;
	TYPE_STATEMENT1_t(TYPE_STATEMENT1_t && move) = default;

	static TYPE_STATEMENT1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	TYPE_STATEMENT1_t,
	val<TYPE_SCOPE_TYPE_CONSTRAINT>,
	val<STATEMENT>
> TYPE_STATEMENT_base;

struct TYPE_STATEMENT: TYPE_STATEMENT_base {
	static TYPE_STATEMENT build(parlex::detail::ast_node const & n);
	explicit TYPE_STATEMENT(TYPE_STATEMENT_base const & value) : TYPE_STATEMENT_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_TYPE_STATEMENT_HPP
