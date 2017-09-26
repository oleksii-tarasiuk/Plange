#include "parlex/details/recognizer.hpp"

#include <functional>

#include "utils.hpp"

namespace parlex {
namespace details {

recognizer::recognizer(std::string const & id) : id(id) {
}

bool recognizer::is_terminal() const { return false; }

std::ostream& operator<<(std::ostream & os, const recognizer & r) { return os << r.id; }

} // namespace details
} // namespace parlex