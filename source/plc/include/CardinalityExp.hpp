#ifndef CARDINALITY_EXP_HPP
#define CARDINALITY_EXP_HPP

#include "UnaryOpExp.hpp"
class CardinalityExp :
	public UnaryOpExp
{
public:
	CardinalityExp(Expression const & subExpression);
	~CardinalityExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //CARDINALITY_EXP_HPP
