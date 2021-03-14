#include<iostream>

int* findFirstNegativePtr(int numbers[], int length) {
	for (int i = 0; i < length; i++) {
		if (numbers[i] < 0) {
			return &numbers[i];
		}
	}

	return NULL; // NULL nullptr
}

int main_03() {
	using namespace std;

	int numbers[]{ 1, 5, 1, 12, 36 };

	int* negativePtr = findFirstNegativePtr(numbers, sizeof(numbers)/sizeof(numbers[0]) );
	if (negativePtr != nullptr) {
		cout << *negativePtr << endl;
	}
	else {
		cout << "no negative numbers" << endl;
	}

	return 0;
}
