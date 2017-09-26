// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_1_HPP
#define INCLUDED_FUNCTION_MODIFIER_1_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct FUNCTION_MODIFIER_2;
struct FUNCTION_MODIFIER_THROWING;

typedef std::variant<
	erased<FUNCTION_MODIFIER_THROWING>,
	erased<FUNCTION_MODIFIER_2>
> FUNCTION_MODIFIER_1;

#endif //INCLUDED_FUNCTION_MODIFIER_1_HPP