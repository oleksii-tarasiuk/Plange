#ifndef ERRORS_H
#define ERRORS_H

#include <string>
#include <iostream>

void emit_error(int warnNumber, std::string description, std::string info);

#define MAKE_ERROR(NAME, DESCRIPTION) inline void emit_##NAME(std::string info) { emit_error(__LINE__ + firstErrorOffset, #DESCRIPTION, info); }

int constexpr firstErrorOffset = -__LINE__;
MAKE_ERROR(AmbiguousParse, More than one interpretation of the input exists.)
MAKE_ERROR(CouldNotParse, The document does not conform to the syntax.)
MAKE_ERROR(CouldNotOpenFile, The file could not be opened.)

#endif //ERRORS_H