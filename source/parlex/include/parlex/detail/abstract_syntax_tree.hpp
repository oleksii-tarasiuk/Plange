#ifndef INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP
#define INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP

#include <string>
#include <vector>

#include "parlex/detail/transition.hpp"

namespace parlex::detail {
class grammar;

struct ast_node : transition {
	std::vector<ast_node> children;

	ast_node(transition const & t, std::vector<ast_node> children);
	std::string to_dot(grammar const & g) const;
};

typedef ast_node abstract_syntax_tree;

}

#endif // INCLUDED_PARLEX_ABSTRACT_SYNTAX_TREE_HPP
