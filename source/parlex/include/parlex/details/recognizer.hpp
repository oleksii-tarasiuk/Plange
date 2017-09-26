#ifndef RECOGNIZER_HPP
#define RECOGNIZER_HPP

#include <string>

namespace parlex {
namespace details {
namespace behavior {

class leaf;

}


//base class for terminal and state_machine_base
class recognizer {
public:
	recognizer(std::string const & id);
	virtual ~recognizer() = default;
	virtual bool is_terminal() const;
	std::string const id;

	friend std::ostream& operator<<(std::ostream & os, const recognizer & r);
};

} // namespace details
} // namespace parlex

#endif //RECOGNIZER_HPP