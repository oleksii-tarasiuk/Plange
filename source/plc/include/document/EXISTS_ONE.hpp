// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EXISTS_ONE_HPP
#define INCLUDED_EXISTS_ONE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct EXISTS_ONE {
	struct field_1_t {
		enum type {
			literal_0xE20x880x830x21,
			literal_exists0x21
		} value;
	
		static field_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar::get().get_literal("literal_0xE20x880x830x21"), literal_0xE20x880x830x21 },
				{ &plange_grammar::get().get_literal("literal_exists0x21"), literal_exists0x21 },
			};
			return field_1_t{ table.find(&n.r)->second };
		}
	};


	field_1_t field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;


	explicit EXISTS_ONE(
		field_1_t && field_1,
		std::vector<erased<IC>> && field_2,
		erased<EXPRESSION> && field_3
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	EXISTS_ONE(EXISTS_ONE const & other) = default;
	EXISTS_ONE(EXISTS_ONE && move) = default;

	static EXISTS_ONE build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_EXISTS_ONE_HPP
