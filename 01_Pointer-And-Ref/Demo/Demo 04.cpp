#include <iostream>
#include <vector>

void printZeroIndices(const std::vector<int>* numbers) {
	for (int i = 0; i < numbers->size(); i++) {
//		if (numbers->at(i) == 0) {
		if ((*numbers)[i] == 0) {
				std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

int main() {
	using namespace std;

	vector<int> numbers{ 1, 0, -2, 7, 0, 10, -100, 42 };
	// NOTE: most compilers would optimize this call by inlining the function,
	// so even if we don't use a reference, the code will execute with similar
	// speed. However, in more complex situations, the compiler won't be able to
	// always inline, so using references to avoid object copies is good practice
	printZeroIndices(&numbers);

	// Pointer Arithmetics Demo
	{
		int number = 42;

		int* intPtr = &number;
		char* charPtr = (char*)&number;

		cout << intPtr << " " << (int*)charPtr << endl;
		intPtr++; charPtr++;
		cout << intPtr << " " << (int*)charPtr << endl;
	}

	// Pointers as arrays
	{
		int arr[3]{ 13, 42, 69 };
		int* p = arr;
		p[1] = -42;
		cout << arr[1] << endl;
		cout << *(p + 1) << endl;
		cout << p[1] << endl;
	}

	// Fun Fact (don't do it in Production!)
	{
		int arr[3] = { 13, 42, 69 };
		int a = 1[arr];
		cout << a << endl;
	}

	return 0;
}
