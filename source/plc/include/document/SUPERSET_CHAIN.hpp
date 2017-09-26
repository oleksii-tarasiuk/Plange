// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SUPERSET_CHAIN_HPP
#define INCLUDED_SUPERSET_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;
struct SUPERSET_CHAIN_LOOP;

struct SUPERSET_CHAIN {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	erased<SUPERSET_CHAIN_LOOP> field_3;

	SUPERSET_CHAIN(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2,
		erased<SUPERSET_CHAIN_LOOP> const & field_3
	) : field_1(field_1), field_2(field_2), field_3(field_3) {}
};



#endif //INCLUDED_SUPERSET_CHAIN_HPP