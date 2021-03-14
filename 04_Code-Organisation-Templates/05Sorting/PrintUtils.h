#ifndef PRINT_UNITS_H
#define PRINT_UNITS_H


template<typename Container>
void printVector(Container container) {
	typename Container::iterator i;
	for (i = container.begin(); i != container.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void printContainer(typename T::iterator begin, typename T::iterator end) {
	while (begin != end) {
		std::cout << *begin << " ";
		++begin;
	}
	std::cout << std::endl;
}

#endif // !PRINT_UNITS_H