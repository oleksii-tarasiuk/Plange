// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_DEREFERENCE_HPP
#define INCLUDED_TYPE_DEREFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;

struct TYPE_DEREFERENCE {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;
	std::vector<erased<IC>> field_3;

	TYPE_DEREFERENCE(
		std::vector<erased<IC>> const & field_1,
		erased<EXPRESSION> const & field_2,
		std::vector<erased<IC>> const & field_3
	) : field_1(field_1), field_2(field_2), field_3(field_3) {}
};



#endif //INCLUDED_TYPE_DEREFERENCE_HPP