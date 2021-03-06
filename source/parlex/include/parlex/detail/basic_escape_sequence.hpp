#ifndef INCLUDED_PARLEX_BASIC_ESCAPE_SEQUENCE_HPP
#define INCLUDED_PARLEX_BASIC_ESCAPE_SEQUENCE_HPP

#include "parlex/detail/terminal.hpp"

namespace parlex::detail {

class basic_escape_sequence_t : public terminal {
public:
	basic_escape_sequence_t();
	bool test(std::u32string const & document, uint32_t documentPosition) const override final;
};

} // namespace parlex

#endif // INCLUDED_PARLEX_BASIC_ESCAPE_SEQUENCE_HPP
