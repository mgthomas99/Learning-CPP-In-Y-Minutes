#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "person.hpp"
#include "util.hpp"

using namespace LCppIYM;

/**
 * Calculate `n` values of the Fibonacci sequence.
 *
 * @param	n
 * 			The number of values to generate.
 * @return	A `std::vector<unsigned long>` containing the values.
 * @throw	`std::runtime_error` if `n < 1`.
 */
std::vector<unsigned long> fib(const unsigned int n = 1)
{
	std::vector<unsigned long> values;
	values.push_back(0);
	values.push_back(1);

	for (unsigned int i = 0; i < n; i++)
	{
		const unsigned long next =
				values[values.size() - 2] + values[values.size() - 1];
		values.push_back(next);
	}
	return values;
}

/**
 * Usage:
 * 		main.bin [n]
 * 
 * 	[n]: The number of items to generate in the Fibonacci sequence.
 * 
 * @return	Error status; 0 means no error occurred.
 */
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		throw std::runtime_error("Syntax:\n\tmain.bin [n]\n");
	}
	
#ifdef RASPBERRY_PI
	std::cout << std::string("Yay RaspberryPi!\n") << std::endl;
#endif

	// Create an instance of `Person` using `new` keyword, just like other
	// C-like languages. The `auto` keyword lets us omit the type specifier for
	// the `me` variable; alternatively, we could write `const Person me = ...`
	// but that seems redundant.
    const auto *me = new Person("John", "Doe");
    
    me->say("Here's the fibonacci sequence");

    for (const auto i : fib( std::stoi(argv[1]) ))
		std::cout << i << std::endl;

    return 0;
}
