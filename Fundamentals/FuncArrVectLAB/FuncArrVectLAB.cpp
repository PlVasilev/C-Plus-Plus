#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>
#include "cmath"
#include <chrono>
#include <string>
#include <array>
#include <vector>

using namespace std;
bool AreArrEqual(int arr[], int arr2[], int size, int size2);
const int length = 1000;

int main()
{
	//									ARREY
	array<int, 3> arr3 = { 0 };
	array<int, 3> arr4 = { 0 };

	int actualLength;
	cin >> actualLength;

	int arr[length];
	for (int i = 0; i < actualLength; i++) {
		cin >> arr[i];
	}

	int actualLength2;
	cin >> actualLength2;

	int arr2[length];
	for (int i = 0; i < actualLength2; i++) {
		cin >> arr2[i];
	}

	const bool result = AreArrEqual(arr, arr2, actualLength, actualLength2);

	result ? cout << "equal" : cout << "not equal";

	for (int /* int = auto*/ i : arr2)
	{
		// cout << i << endl;
	}


	//									VECTOR
	/*vector<int> numbers{ 13, 42, 69 };

	vector<int> vector1;
	int num1;
	cin >> num1;

	for (int i = 0; i < num1; ++i)
	{
		int input;
		cin >> input;
		vector1.push_back(input);
	}*/


}

bool AreArrEqual(int arr[], int arr2[], int size, int size2)
{
	if (size == size2)
	{
		for (int i = 0; i <= size; ++i)
		{
			if (arr[i] == arr2[i]) continue;
			return false;
		}
		return true;
	}
	return false;

}

