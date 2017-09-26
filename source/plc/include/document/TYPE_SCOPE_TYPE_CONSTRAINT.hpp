// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_HPP
#define INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct IC;
struct TYPE_CONSTRAINT_HEAD;
struct TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN;

struct TYPE_SCOPE_TYPE_CONSTRAINT {
	erased<TYPE_CONSTRAINT_HEAD> field_1;
	std::vector<erased<IC>> field_2;
	erased<TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN> field_3;

	TYPE_SCOPE_TYPE_CONSTRAINT(
		erased<TYPE_CONSTRAINT_HEAD> const & field_1,
		std::vector<erased<IC>> const & field_2,
		erased<TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN> const & field_3
	) : field_1(field_1), field_2(field_2), field_3(field_3) {}
};



#endif //INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_HPP