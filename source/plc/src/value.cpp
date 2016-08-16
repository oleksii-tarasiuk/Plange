#include "value.hpp"
#include "Errors.hpp"

value::value(value* type, const std::vector<int8_t>& storage) : type(type), storage(storage) { }

bool value::operator==(value const & rhs)
{
	ERROR(NotImplemented, __FUNCTION__);
}