// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_REGEX_HPP
#define INCLUDED_REGEX_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct STRING;

struct REGEX {
	erased<STRING> field_1;

	REGEX(
		erased<STRING> const & field_1
	) : field_1(field_1) {}
};



#endif //INCLUDED_REGEX_HPP
