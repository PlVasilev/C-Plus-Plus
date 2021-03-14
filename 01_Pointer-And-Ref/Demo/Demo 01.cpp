#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

int myStaticVal = 0;

void swap(int& a, int& b) {
	int oldA = a;
	a = b;
	b = oldA;
}

void removeNegative(std::list<int>& numbers) {
	auto i = numbers.begin();
	while (i != numbers.end()) {
		if (*i < 0) {
			i = numbers.erase(i);
		}
		else {
			i++;
		}
	}
}


void printZeroIndices(const std::vector<int> numbers) {
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 0) {
			std::cout << i << " ";
		}
	}
	cout << endl;
}

std::vector<int>& generateRoots(int toNumber) {
	std::vector<int> roots;
	for (int i = 0; i < toNumber; i++) {
		roots.push_back(sqrt(i));
	}
	return roots;
}

class LetterFilter {
	const std::string& s;
	int index;
public:
	LetterFilter(const std::string& s)
		: s(s), index(0) {
	}

	char nextLetterOrNull() {
		while (index < s.size() && !isalpha(s[this->index])) {
			this->index++;
		}

		if (this->index == s.size()) {
			return 0;
		}

		return s[this->index++];
	}
};

int main_01() {
	int x = 13, y = 42;
	swap(x, y); // x == 42, y == 13
	std::cout << x << " " << y << std::endl;

	std::list<int> values{ 1, -69, -4, 42, -2, 13, -9 };
	removeNegative(values); // values{ 1, 42, 13 };

	for (int v : values) {
		std::cout << v << " ";
	}
	std::cout << std::endl;

	vector<int> numbers{ 1, 0, -2, 7, 0, 10, -100, 42 };
	// NOTE: most compilers would optimize this call by inlining the function,
	// so even if we don't use a reference, the code will execute with similar
	// speed. However, in more complex situations, the compiler won't be able to
	// always inline, so using references to avoid object copies is good practice
	printZeroIndices(numbers);

	// generateRoots() ERROR
	//// NOTE: it is possible that this code will seem to work as expected,
	//// as the program is short and the memory could still remain the same
	//// even after being freed. But it is not guaranteed to work, especially
	//// in a real, non-debug environment, where the memory freed by the vector
	//// is likely to be overwritten at some point by another program, or even
	//// the same program
	//std::vector<int>& rootsRef = generateRoots(100);

	//// NOTE 2: this otherVector is here to simulate a real environment, where
	//// additional memory allocations might overwrite the freed memory. Under
	//// Windows, in Code::Blocks with MinGW this otherVector seems to overwrite that memory,
	//// making the printed value different. But it is not 100% guaranteed, especially
	//// if we change the environment or the compiler. This is exactly why the behavior
	//// is "undefined" - we cannot be sure what will happen, because the C++ standard
	//// does not place a strict requirement on what should happen, hence different
	//// compilers can create code that behaves differently in different situations
	//std::vector<int> otherVector{ 42, 13, 69 };
	//std::cout << rootsRef[4] << std::endl;

	//std::cout << &rootsRef;
	//for (int v : rootsRef) {
	//	std::cout << v << " ";
	//}
	//std::cout << std::endl;


	// Reference Limitations
	string text = "abc 32 a98c";
	LetterFilter filter(text);
	char c;
	while (c = filter.nextLetterOrNull()) {
		cout << c;
	}

	return 0;
}
