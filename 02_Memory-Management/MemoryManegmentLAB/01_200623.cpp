#include <iostream>
#include <vector>
#include <ostream>

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& v) {
	for (T item : v) {
		stream << item << " ";
	}

	return stream;
}

std::vector<int> filter(std::vector<int> numbers, bool(*shouldFilter)(int)) {
	std::vector<int> filtered;


	for (int n : numbers) {
		if (shouldFilter(n)) {
			filtered.push_back(n);
		}
	}

	return filtered;
}

bool isEven(int number) {
	return number % 2 == 0;
}

bool isGreaterThan3(int number) {
	return number > 3;
}

bool isNegative(int number) {
	return number < 0;
}

int main_voidStar() {
	using namespace std;

	double a = 50.50;
	char c = 4;

	c = (char)a;

	void* pp = &main_voidStar;
	double* dp = &a;

	pp = &a;
	dp = (double *)pp;

	cout << filter({ 1, 2, 3, 4, 5, 6, 7 }, isEven) << endl;

	cout << filter({ 1, 2, 3, 4, 5, 6, 7 }, isGreaterThan3) << endl;

	cout << filter({ -1, 2, -3, 4, -5, 6, 7 }, isNegative) << endl;

	return 0;
}
