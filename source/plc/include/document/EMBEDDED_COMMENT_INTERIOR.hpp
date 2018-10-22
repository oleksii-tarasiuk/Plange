﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_COMMENT_INTERIOR_HPP
#define INCLUDED_EMBEDDED_COMMENT_INTERIOR_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EMBEDDED_COMMENT_INTERIOR;
struct PAYLOAD;

struct EMBEDDED_COMMENT_INTERIOR_t {
	parlex::detail::document::text<literal_0x2A_t> dont_care0;
	
	val<EMBEDDED_COMMENT_INTERIOR> field_1;
	
	parlex::detail::document::text<literal_0x2A_t> dont_care2;
	


	explicit EMBEDDED_COMMENT_INTERIOR_t
		(parlex::detail::document::text<literal_0x2A_t> const & dont_care0, val<EMBEDDED_COMMENT_INTERIOR> const & field_1, parlex::detail::document::text<literal_0x2A_t> const & dont_care2)
		: dont_care0(dont_care0), field_1(field_1), dont_care2(dont_care2) {}

	EMBEDDED_COMMENT_INTERIOR_t(EMBEDDED_COMMENT_INTERIOR_t const & other) = default;
	static EMBEDDED_COMMENT_INTERIOR_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	val<PAYLOAD>,
	EMBEDDED_COMMENT_INTERIOR_t
> EMBEDDED_COMMENT_INTERIOR_base;

struct EMBEDDED_COMMENT_INTERIOR: EMBEDDED_COMMENT_INTERIOR_base {
	static EMBEDDED_COMMENT_INTERIOR build(parlex::detail::ast_node const & n);
	explicit EMBEDDED_COMMENT_INTERIOR(EMBEDDED_COMMENT_INTERIOR_base const & value) : EMBEDDED_COMMENT_INTERIOR_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_EMBEDDED_COMMENT_INTERIOR_HPP
