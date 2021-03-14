#include <iostream>
#include <ostream>

#include "Defines.h"

int main() {
#ifndef DONT_COMPILE_THIS
	this here has compilation errors : )
#endif // !DONT_COMPILE_THIS
	using STANDARD_TEMPLATE_LIBRARY;
	std::string input;
	std::cin >> input;
	std::cout << input << std::endl;

	return 0;
}