// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NOT_IN_HPP
#define INCLUDED_NOT_IN_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;

struct NOT_IN {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>
	> field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;

	NOT_IN(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2,
		std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>
		> const & field_3,
		std::vector<erased<IC>> const & field_4,
		erased<EXPRESSION> const & field_5
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}
};



#endif //INCLUDED_NOT_IN_HPP