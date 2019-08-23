#include <iostream>
#include <string>

#include "util.hpp"

using namespace LCppIYM;

/**
 * Read the next line from the standard input stream.
 *
 * @return	A `std::string` containing the input.
 */
std::string LCppIYM::readline()
{
	std::string x;
	std::cin >> x;
	return x;
}
