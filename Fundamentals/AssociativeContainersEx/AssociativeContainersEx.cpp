#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <list>
#include <math.h> 
using namespace std;

int main()
{
	// EX1
	// string line3; getline(cin, line3);
	// istringstream lineStream(line3);
	// vector<double> numbers;
	// double currentNumber;
	// while (lineStream >> currentNumber) numbers.push_back(currentNumber);
	// map<double, int> numbersDic;
	// for (unsigned long i = 0; i < numbers.size(); i++) numbersDic[numbers[i]]++;
	// map<double, int>::iterator it;
	// for (it = numbersDic.begin(); it != numbersDic.end(); it++) cout << it->first << " -> " << it->second << endl;

	//EX 2
	// string line3; getline(cin, line3);
	// istringstream lineStream(line3);
	// vector<string> numbers;
	// string currentNumber;
	// while (lineStream >> currentNumber) numbers.push_back(currentNumber);
	// 
	// vector<pair< string, int>> dic;
	// for (unsigned long i = 0; i < numbers.size(); i++)
	// {
	// 	auto word = transform(numbers[i].begin(), numbers[i].end(), numbers[i].begin(),
	// 		[](unsigned char c) { return std::tolower(c); });
	// 
	// 	bool found = false;
	// 	for (int j = 0; j < dic.size(); ++j)
	// 	{
	// 		if (dic[j].first == numbers[i])
	// 		{
	// 			dic[j].second++;
	// 			found = true;
	// 			break;
	// 		}
	// 	}
	// 	if (!found) dic.push_back({ numbers[i] , 1 });
	// }
	// 
	// bool isPrinted = false;
	// 
	// vector<pair< string, int>>::iterator it;
	// for (it = dic.begin(); it != dic.end(); it++)
	// {
	// 	if (it->second % 2 != 0)
	// 	{
	// 		if (!isPrinted)
	// 		{
	// 			cout << it->first;
	// 			isPrinted = true;
	// 		}
	// 		else cout << ", " << it->first;
	// 	}
	// }

	//EX3
	//string line3; getline(cin, line3);
	//istringstream lineStream(line3);
	//list<double> numbers;
	//double currentNumber;
	//while (lineStream >> currentNumber) numbers.push_back(currentNumber);
	//
	//int counter = 0;
	//
	//numbers.sort(std::greater<int>());
	//for (double num : numbers)
	//{
	//	if (counter == 3) break;
	//	cout << num << " ";
	//	counter++;
	//}

	// EX 4
	// string line3; getline(cin, line3);
	// istringstream lineStream(line3);
	// vector<string> numbers;
	// string currentNumber;
	// while (lineStream >> currentNumber) numbers.push_back(currentNumber);
	// set<string> words;
	// 
	// for (unsigned long i = 0; i < numbers.size(); i++)
	// {
	// 	auto word = transform(numbers[i].begin(), numbers[i].end(), numbers[i].begin(),
	// 		[](unsigned char c) { return std::tolower(c); });
	// 
	// 	if (numbers[i].size() < 5) words.insert(numbers[i]);
	// }
	// 
	// bool start = true;
	// 
	// for (set<string>::iterator i = words.begin(); i != words.end(); i++)
	// {
	// 	if (start)
	// 	{
	// 		cout << *i;
	// 		start = false;
	// 	}
	// 	else 	cout << ", " << *i;
	// }
	// cout << endl;

	// EX5
	//string line3; getline(cin, line3);
	//istringstream lineStream(line3);
	//set<double> numbers;
	//double currentNumber;
	//while (lineStream >> currentNumber) numbers.insert(currentNumber);
	//
	//bool start = true;
	//
	//for (set<double>::iterator i = numbers.begin(); i != numbers.end(); i++)
	//{
	//	if (start)
	//	{
	//		cout << *i;
	//		start = false;
	//	}
	//	else 	cout << " <= " << *i;
	//}

	// EX 6
	// string line3; getline(cin, line3);
	// istringstream lineStream(line3);
	// list<double> numbers;
	// double currentNumber;
	// while (lineStream >> currentNumber) numbers.push_back(currentNumber);
	// 
	// list<int> result;
	// for (list<double>::iterator i = numbers.begin(); i != numbers.end(); i++)
	// {
	// 	long double sr = sqrt(*i);
	// 	if ((sr - floor(sr)) == 0) result.push_back(*i);
	// }
	// 
	// result.sort(std::greater<int>());
	// for (int num : result)
	// {
	// 	cout << num << " ";
	// }

	string input;
	int inputInt;
	vector<pair<string, int>> result;

	while (std::cin >> input && input != "stop" && std::cin >> inputInt)
	{
		bool found = false;
		for (int j = 0; j < result.size(); ++j)
		{
			if (result[j].first == input)
			{
				result[j].second += inputInt;
				found = true;
				break;
			}
		}
		if (!found) result.push_back({ input, inputInt });
	}

	for (auto iter = result.begin(); iter != result.end(); iter++) 
		cout << iter->first << " -> " << iter->second << endl;
	


}
