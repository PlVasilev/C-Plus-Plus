#ifndef HEADER_GUARDED_FILE_H
#define HEADER_GUARDED_FILE_H

#include <iostream>

class HeaderGuarded {
public:
	int a;
};

void headerGuardedFileFunction() {
	std::cout << "includeGuardedFileFunction" << std::endl;
}

#endif // !HEADER_GUARDED_FILE_H