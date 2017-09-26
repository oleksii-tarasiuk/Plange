// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DATE_TIME_HPP
#define INCLUDED_DATE_TIME_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct DATE;
struct TIME;

struct DATE_TIME {
	erased<DATE> field_1;
	erased<TIME> field_2;

	DATE_TIME(
		erased<DATE> const & field_1,
		erased<TIME> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_DATE_TIME_HPP