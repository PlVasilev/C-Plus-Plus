#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

// problem 1

void problem1()
{
	int left, right;
	char operation = 0;
	double result;

	cin >> left >> right;

	while (!operation)
	{
		cin >> operation;
		
		switch (operation)
		{
		case '+': result = (double)left + right; break;
		case '-': result = (double)left - right; break;
		case '*': result = (double)left * right; break;
		case '/': result = (double)left / right; break;
		default:
			operation = 0;
			cout << "try again" << endl; break;
		}
	}

	cout << result;
}

void problem2() {

	int size;
	vector<int> arr;

	cin >> size;

	while (size) {
		int i;
		cin >> i;
		arr.push_back(i);
		size--;
	}

	int key;
	unsigned index;
	cin >> key;

	for (index = 0; index < arr.size(); index++)
		if (arr[index] == key)
			break;

	// cout << (index < arr.size() ? (int)index : -1);  // (bool expression) ? (consider if true) : (consider if false)

	if (index < arr.size())
		cout << index;
	else
		cout << -1;
}

void problem3() {
	int size;
	vector<int> arr;

	cin >> size;

	while (size) {
		int i;
		cin >> i;
		arr.push_back(i);
		size--;
	}

	int key;
	unsigned index;
	cin >> key;
	vector<int> result;
	
	for (index = 0; index < arr.size(); index++)
		// check if arr[index] == key
		if (arr[index] != key)
			result.push_back(arr[index]);

	for (index = 0; index < result.size(); index++)
		cout << result[index] << " ";
}

int ReadIntWithNoise(string str) {
	unsigned index = 0;
	int number = 0;

	for (index = 0; index < str.length(); index++) {
		char symbol = str[index];
		if (symbol >= '0' && symbol <= '9') {
			number = number * 10;  // up number with ^10
			number = number + (symbol - '0');  // add the new number 
		}
		else
			if (symbol == '.')
				break;
	}

	return number;
}

void problem4() {

	int number = 0;
	char symbol;

	do {
		cin >> symbol;
		if (symbol >= '0' && symbol <= '9') {
			number = number * 10;  // up number with ^10
			number = number + (symbol - '0');  // add the new number 
		}
	} while (symbol != '.');

	cout << sqrt(number);

}

void problem5() {

	// initialize pseudorandom generator
	srand((unsigned)time(NULL));

	// get the size of the random sequence
	int count = 100; // ((unsigned)rand()) % 100 + 1; // count ==> 1 .. 65

	string str;
	for (; count; count--)
		str.push_back((char)(rand()));

	cout << "Generated sequence: " << endl;
	cout << str << endl;
	cout << "=============" << endl;

	int result = ReadIntWithNoise(str);
	cout << "Our number is: " << result << endl;
	cout << "sqrt(result) = " << sqrt(result) << endl;

}

void problem6() {

	int n;
	cin >> n;

	for(int s1 = 0; s1 < n; s1++)
		for (int s2 = 0; s2 < n; s2++)
			for (int s3 = 0; s3 < n; s3++)
				cout << (char)(s1 + 'a') << (char)(s2 + 'a') << (char)(s3 + 'a') << endl;
}

string DigitToWord(int digit) {
	switch (digit) {
	case 1: return "one"; break;
	case 2: return "two"; break;
	case 3: return "three"; break;
	case 4: return "four"; break;
	case 5: return "five"; break;
	case 6: return "six"; break;
	case 7: return "seven"; break;
	case 8: return "eight"; break;
	case 9: return "nine"; break;
	default: return ""; break;
	}
}

void problem7() {

	int number; 

	cin >> number;

	if (number == 0)
	{
		cout << "zero";
		return;
	}
	if (number < 0 || number > 9999)
	{
		cout << "Error! Expected number between 0 and 9999." << endl;
		return;
	}

	int d1, d2, d3, d4; // d1 d2 d3 d4
						//  1  2  4  5 ==> 1245

	d1 =  number / 1000;		// => d1
	d2 = (number % 1000) / 100; // => d2
	d3 = (number % 100) / 10;	// => d3
	d4 =  number % 10;			// => d4

	if (d1)
		cout << DigitToWord(d1) << " thousand ";
	if (d2)
		cout << DigitToWord(d2) << " hundred ";
	if (d3)
		switch (d3) {
		case 1: cout << "ten "; break;
		case 2: cout << "twenty "; break;
		case 3: cout << "thirty "; break;
		case 4: cout << "fourty "; break;
		case 5: cout << "fifty "; break;
		case 6: cout << "sixty "; break;
		case 7: cout << "seventy "; break;
		case 8: cout << "eighty "; break;
		case 9: cout << "ninety "; break;
		}
	if (d4)
		cout << DigitToWord(d4);
}

void problem8() {
	
	int number;

	cin >> number;

	int m1 = 0, m2 = 0; // m1 -> sum of the odd digits; m2 -> sub of the even digits

	while (number) // 12345
	{
		// get the odd digit of the number
		int oddpart = number % 10; // 1234<5>
		m1 += oddpart;  // m1 = m1 + oddpart
		number = number / 10; // <1234> 

		// get the even digit of the number (this "new odd" digit)
		int evenpart = number % 10; // 123<4>
		m2 += evenpart;
		number = number / 10; // <123>
	}

	cout << m1 * m2; 
}

void problem9() {

	int size;
	vector<int> arr;

	cin >> size;

	while (size) {
		int i;
		cin >> i;
		arr.push_back(i);
		size--;
	}

	vector<int> result;
	unsigned index;

	while (1) {
		for (index = 0; index < arr.size(); index++)
		{
			if ( index < (arr.size() - 1) && 
				 (arr[index] == arr[index + 1]) )
			{
				result.push_back(arr[index] * 2);
				index++;
			}
			else
				result.push_back(arr[index]);
		}
		if (result.size() == arr.size())
			break;

		arr = result; // the next pass will take the new array
		result.clear(); // resulting array must be empty
	}

	for (index = 0; index < result.size(); index++)
		cout << result[index] << " ";

}

int main()
{
	problem9();
}
