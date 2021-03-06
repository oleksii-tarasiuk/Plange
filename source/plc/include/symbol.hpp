#ifndef INCLUDED_PLC_SYMBOL_HPP
#define INCLUDED_PLC_SYMBOL_HPP

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "visibility.hpp"
#include <optional>
#include "val.hpp"

namespace plc {

class analytic_value;

class symbol {
public:
	symbol(
		std::u32string name,
		std::optional<val<analytic_value>> value,
		std::optional<val<analytic_value>> type,
		ptr<analytic_value> const & scope,
		bool is_variable,
		bool is_local,
		std::u32string xml_doc_string,
		std::vector<val<analytic_value>> attributes,
		visibility visibility,
		bool is_extern,
		bool is_static,
		bool is_volatile
	);

	symbol & operator=(symbol const & other) = delete;

	std::u32string const & get_name() const;
	std::optional<val<analytic_value>> const & get_value() const;
	void set_value(val<analytic_value> const & newValue);
	bool get_is_variable() const;
	void set_xml_doc_string(std::u32string const & xmlDocString);
	std::u32string const & get_xml_doc_string() const;

private:
	//is unbound if is_variable && value.get() == nullptr
	std::u32string name_;
	std::optional<val<analytic_value>> value_;
	std::optional<val<analytic_value>> type_;
	ptr<analytic_value> scope_;
	bool is_variable_; // constant if false
	bool is_local_;
	std::u32string xml_doc_string_;
	std::vector<val<analytic_value>> attributes_;
	visibility visibility_;
	bool is_extern_;
	bool is_static_;
	bool is_volatile_;
	std::optional<int> member_offset_;
};

}

#endif // INCLUDED_PLC_SYMBOL_HPP
