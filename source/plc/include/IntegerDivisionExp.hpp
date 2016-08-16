#ifndef INTEGER_DIVISION_EXP_HPP
#define INTEGER_DIVISION_EXP_HPP

#include "BinaryOpExp.hpp"
class IntegerDivisionExp :
	public BinaryOpExp
{
public:
	IntegerDivisionExp();
	~IntegerDivisionExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //INTEGER_DIVISION_EXP_HPP