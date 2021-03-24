#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

int main()
{	// EX!
	/*   stack<string> result;
	   string line;
	   getline(cin, line);
	   while (line != "end")
	   {
		   istringstream lineStream(line);
		   string word;
		   while (lineStream >> word) result.push(word);
		   getline(cin, line);
	   }

	   while (!result.empty())
	   {
		   cout << result.top() << " ";
		   result.pop();
	   }*/

	   // EX2
	//string input, first, second;
	//cin >> input >> first >> second;

	//vector<int> resultFirst, resultSecond;

	//istringstream lineStream(input);
	//
	//for (int i = 0; i < first.size(); ++i)
	//{
	//	for (int j = 0; j < input.size(); ++j)
	//	{
	//		if (input[j] == first[i]) resultFirst.push_back(j);
	//	}
	//}

	//for (int i = 0; i < second.size(); ++i)
	//{
	//	for (int j = 0; j < input.size(); ++j)
	//	{
	//		if (input[j] == second[i]) resultSecond.push_back(j);	
	//	}
	//}

	//int resultFirstInt = 0;
	//for (int i = resultFirst.size() - 1; i >= 0; --i)
	//resultFirstInt += resultFirst[resultFirst.size() - 1 -i] *(pow(10, i));
	//
	//int resultSecondInt = 0;
	//for (int i = resultSecond.size() - 1; i >= 0; --i)
	//resultSecondInt += resultSecond[resultSecond.size() - 1 - i] * (pow(10, i));
	//
	//int resultInt = resultFirstInt + resultSecondInt;

	// // string s = to_string(resultInt);

	//std::string answer;
	//std::string numberStr = std::to_string(resultInt);
	//answer.resize(numberStr.size());

	//for (size_t i = 0; i < numberStr.size(); ++i)
	//{
	//	const int index = numberStr[i] - '0';

	//	answer[i] = input[index];
	//}

	//cout << answer;

	//EX3
	/*vector<vector<char>> numbersArr;

	int rows, columns;
	cin >> rows >> columns;
	cin.ignore();
	for (int i = 0; i < rows; ++i)
	{
		string line3; getline(cin, line3);
		istringstream lineStream(line3);
		vector<char> numbers;
		char currentChar;
		while (lineStream >> currentChar) numbers.push_back(currentChar);
		numbersArr.push_back(numbers);
	}

	vector<vector<int>> result;

	for (int i = 0; i < rows; ++i)
	{
		vector<int> resultRow;
		for (int j = 0; j < columns; ++j)
		{
			resultRow.push_back(0);
		}
		result.push_back(resultRow);
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			if (numbersArr[i][j] == '!')
			{
				if (i > 0)
				{
					if (j > 0) result[i - 1][j - 1] += 1;
					result[i - 1][j] += 1;
					if (j < columns - 1) result[i - 1][j + 1] += 1;
				}

				if (j > 0) result[i][j - 1] += 1;
				result[i][j] += 1;
				if (j < columns - 1) result[i][j + 1] += 1;

				if (i < rows - 1)
				{
					if (j > 0) result[i + 1][j - 1] += 1;
					result[i + 1][j] += 1;
					if (j < columns - 1) result[i + 1][j + 1] += 1;
				}

			}
		}
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			cout << result[i][j];
		}
		cout << endl;
	}*/


	//EX4
	/*vector<vector<char>> numbersArr;

	for (int i = 0; i < 10; ++i)
	{
		string line3; getline(cin, line3);
		istringstream lineStream(line3);
		vector<char> numbers;
		char currentChar;
		while (lineStream >> currentChar) numbers.push_back(currentChar);
		numbersArr.push_back(numbers);
	}

	int num;
	cin >> num;

	vector<vector<char>> result;

	for (int i = 0; i < 10; ++i)
	{
		vector<char> resultRow;
		for (int j = 0; j < 10; ++j)
		{
			resultRow.push_back('.');
		}
		result.push_back(resultRow);
	}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (numbersArr[i][j] == '#')
			{
				result[i][j] = '#';
			}
		}
	}

	while (num > 0)
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (numbersArr[i][j] == '!')
				{
					result[i][j] = '!';
					if (i > 0 ) numbersArr[i - 1][j] != '#' ? result[i - 1][j] = '!' : result[i - 1][j] = '#';
					if (j > 0 ) numbersArr[i][j - 1] != '#' ? result[i][j - 1] = '!' : result[i][j - 1] = '#';
					if (j < 9 ) numbersArr[i][j + 1] != '#' ? result[i][j + 1] = '!' : result[i][j + 1] = '#';
					if (i < 9 ) numbersArr[i + 1][j] != '#' ? result[i + 1][j] = '!' : result[i + 1][j] = '#';
				}
			}
		}
		numbersArr = result;
		num--;
	}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << numbersArr[i][j];
		}
		cout << endl;
	}*/

	// EX5
	vector<string> result;
	string line;
	getline(cin, line);
	istringstream lineStream(line);
	string word;
	while (lineStream >> word) {
		int wordStart = 0;
		for (int i = 0; i < word.size(); ++i)
		{
			if (word[i] == '.' || word[i] == ',' || word[i] == ':' || word[i] == '!' || word[i] == '.' || word[i] == '?' || word[i] == ';' || word[i] == '\'' || word[i] == '\"')
			{
				string realWord;
				realWord = word.substr(wordStart, i);
				if (!realWord.empty())
				{
					result.push_back(realWord);
				}
				string s(1, word[i]);
				result.push_back(s);
				wordStart = i + 1;
			}
			if (i == word.size() - 1)
			{
				string finalWord;
				finalWord = word.substr(wordStart, i + 1);
				if (!finalWord.empty())
				{
					result.push_back(finalWord);
				}
			}
		}
	}

	for (int i = 0; i < result.size(); ++i)
	{
		if (result[i].size() == 1)
		{
			continue;
		}
		for (int j = result.size() - 1 - i ; j > i; --j)
		{
		
			if (result[i].size() == result[j].size())
			{
				string wordToSwap = result[i];
				string swappedWord = result[j];

				if (std::isupper(wordToSwap[0]))
				{
					wordToSwap[0] = std::tolower(wordToSwap[0]);
					swappedWord[0] = std::toupper(swappedWord[0]);
				}
				result[i] = swappedWord;
				result[j] = wordToSwap;
				break;
			}
			
		}
	}
	
	for (vector<string>::iterator i = result.begin(); i != result.end(); i++) {
		if (i == result.begin())
		{
			cout << *i;
		}
		else if (*i == "." || *i == "," ||
			*i == ":" || *i == "!"||
			*i == "." || *i == "?" ||
			*i == ";"|| *i == "\'" ||
			*i == "\"")
		{
			cout << *i;
		}
		else
		{
			cout << " " << *i;
		}
	}
}

