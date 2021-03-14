#include <iostream>

/* 
5
3 1 2 3
2 4 5
3 0 1 2
7 1 1 1 1 1 1 1
5 65 12 1 2 3
*/

int main_05() {
	using namespace std;

	int n;
	cin >> n;

	int maxSum = 0;
	int maxSumArrLength = 0;
	int* maxSumArr = nullptr;

	for (int i = 0; i < n; i++) {
		int length;
		cin >> length;

		int sum = 0;
		int* arr = new int[length];
		for (int arrInd = 0; arrInd < length; arrInd++) {
			cin >> arr[arrInd];
			sum += arr[arrInd];
		}

		if (maxSumArr == nullptr || maxSum < sum) {

			if (maxSumArr != nullptr)
				delete maxSumArr;

			maxSum = sum; // memorize the current max sum
			maxSumArr = arr; // memorize the current array (because it's with max sum)
			maxSumArrLength = length; // memorize the current max sum array length
		}
		else {
			delete[] arr;
		}
	}

	cout << endl;
	for (int i = 0; i < maxSumArrLength; i++) {
		cout << maxSumArr[i] << " ";
	}
	delete[] maxSumArr;
	cout << endl;

	return 0;
}
