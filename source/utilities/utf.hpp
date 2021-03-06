#ifndef INCLUDED_UTILITIES_UTF_HPP
#define INCLUDED_UTILITIES_UTF_HPP

#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

#include <string>

std::string to_utf8(std::string const & s);
std::string to_utf8(std::u32string const & s);
std::string to_utf8(std::wstring const & s);
std::wstring to_wstring(std::wstring const & s);
std::wstring to_wstring(std::string const & s);
std::wstring to_wstring(std::u32string const & s);
std::u16string to_utf16(std::string const & s);
std::u16string to_utf16(std::u16string const & s);
std::u32string to_utf32(std::u32string const & s);
std::u32string to_utf32(std::string const & s);
std::u32string to_utf32(std::wstring const & s);
std::u32string read_with_bom(std::istream && src);

#endif // INCLUDED_UTILITIES_UTF_HPP