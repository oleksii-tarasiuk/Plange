#ifndef DOCUMENT_REPRESENTATION_HPP
#define DOCUMENT_REPRESENTATION_HPP

#include <map>

#include "builder.hpp"

namespace parlex {
namespace details {

// a leaf node that may reduce its parent's representation to a simpler form
struct unit : node {
	unit(node const & n);
	node const & original_leaf;
};

// a leaf node representing a data structure
struct aggregate : node {
	std::vector<std::pair<std::string /* data member name */, erased<node>>> data_members;
	void add_member(std::string const & name, erased<node> const & type);
};

erased<node> compute_document_representation(erased<node> const & root);

} // namespace details
} // namespace parlex

#endif //DOCUMENT_REPRESENTATION_HPP