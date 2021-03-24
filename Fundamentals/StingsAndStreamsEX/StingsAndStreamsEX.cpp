
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>


using namespace  std;

int main()
{
	//									Compare Arrays Again
	//string line3; getline(cin, line3);
	//string line4; getline(cin, line4);
	//istringstream lineStream(line3);
	//istringstream lineStream2(line4);
	//vector<int> numbers;
	//vector<int> numbers2;
	//int currentNumber;
	//while (lineStream >> currentNumber) numbers.push_back(currentNumber);
	//while (lineStream2 >> currentNumber) numbers2.push_back(currentNumber);
	//numbers == numbers2 ? cout << "equal" : cout << "not equal";

	//									Mathematical Expression
	// string line3; getline(cin, line3);
	// int foundIndex = line3.find("(");
	// int left = 0;
	// int right = 0;
	// while (foundIndex != string::npos) {
	// 	left++;
	// 	foundIndex = line3.find("(", foundIndex + 1);
	// }
	// int foundIndex2 = line3.find(")");
	// while (foundIndex2 != string::npos) {
	// 	right++;
	// 	foundIndex2 = line3.find(")", foundIndex2 + 1);
	// }
	// left == right ? cout << "correct" : cout << "incorrect";

	//									Title Case
	//string line3; getline(cin, line3);
	//istringstream lineStream(line3);
	//vector<string> numbers;
	//string currentNumber;
	//while (lineStream >> currentNumber) {
	//	if (std::isalpha(currentNumber[0]) && !std::isupper(currentNumber[0]))
	//	{
	//		currentNumber[0] -= 32;
	//	}
	//	for (int i = 1; i < currentNumber.length() - 1; ++i)
	//	{
	//		if (!std::isalpha(currentNumber[i]))
	//		{
	//			if (std::isalpha(currentNumber[i + 1]) && !std::isupper(currentNumber[i + 1]))
	//			{
	//				currentNumber[i + 1] -= 32;
	//			}
	//		}
	//	}
	//	numbers.push_back(currentNumber);
	//}
	//for (const auto& number : numbers) cout << number << " ";

	//									Replace All
	//string line3; getline(cin, line3);
	//istringstream lineStream(line3);
	//string first;
	//string replaced;
	//cin >> first >> replaced;
	//while (line3.find(first) != string::npos) line3.replace(line3.find(first), first.length(), replaced);
	//cout << line3 << endl;

	//									Invalid Input
	// string line3; getline(cin, line3);
	// istringstream lineStream(line3);
	// vector<string> errors;
	// int sum = 0;
	// string currentNumber;
	// while (lineStream >> currentNumber) {
	// 	try
	// 	{
	// 		sum += stoi(currentNumber);
	// 	}
	// 	catch (...)
	// 	{
	// 		errors.push_back(currentNumber);
	// 	}
	// }
	// cout << sum << endl;
	// for (const auto& error : errors)
	// {
	// 	cout << error << " ";
	// }


	//										The Signal and the Noise
	// string line3; getline(cin, line3);
	// istringstream lineStream(line3);
	// int max = INT_MIN;
	// string currentString;
	// while (lineStream >> currentString)
	// {
	// 	string currentNumber = "0";
	// 	for (int i = 0; i < currentString.length(); ++i)
	// 	{
	// 		if (std::isdigit(currentString[i]))
	// 		{
	// 			 currentNumber += currentString[i];
	// 		}
	// 	}
	// 	int current = stoi(currentNumber);
	// 
	// 	if (max < current)
	// 	{
	// 		max = current;
	// 	}
	// 
	// }
	// cout << max;

	string line3; getline(cin, line3);
	istringstream lineStream(line3);
	vector<string> noises;
	string currentString;
	while (lineStream >> currentString)
	{
		string currentNoise = "";
		for (int i = 0; i < currentString.length(); ++i)
		{
			if (currentString[i] < 48 || currentString[i] > 57)
			{
				currentNoise += currentString[i];
			}
		}
		if (currentNoise == "")
		{
			continue;
		}
		noises.push_back(currentNoise);
	}

	if (noises.empty())
	{
		cout << "no noise";
		return 0;
	}

	string smallest = "";
	for (int i = 0; i < noises.size(); ++i)
	{
		if (i == 0)
		{
			smallest = noises[i];
		}
		if (smallest.length() < noises[i].size())
		{
			smallest = noises[i];
		}
		else if (smallest.length() == noises[i].size())
		{
			if (smallest > noises[i])
			{
				smallest = noises[i];
			}
		}
	}
	cout << smallest;

}


