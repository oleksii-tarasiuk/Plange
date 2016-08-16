#include "KleeneStarExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



KleeneStarExp::KleeneStarExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


KleeneStarExp::~KleeneStarExp()
{
}

std::u32string KleeneStarExp::get_name() const
{
	return U"*";
}

bool KleeneStarExp::get_postfix() const
{
	return true;
}

value KleeneStarExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}