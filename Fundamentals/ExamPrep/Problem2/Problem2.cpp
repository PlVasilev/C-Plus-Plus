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
#include <stack>
using namespace std;

int main()
{
	vector<vector<int>> numbersArr;
	int rows;
	cin >> rows;

	vector<int> numbers;
	std::cin.ignore();
	string line3;
	getline(std::cin, line3);
	std::istringstream iss(line3);
	int enterNumber;
	while (iss >> enterNumber)
	{
		numbers.push_back(enterNumber);
	}

	int result = 0;
	int counter = 0;

	for (int i = 0; i < numbers.size() / rows; ++i)
	{
		vector<int> matrixRow;
		for (int j = 0; j < rows; ++j)
		{
			matrixRow.push_back(numbers[counter]);
			counter++;
		}
		numbersArr.push_back(matrixRow);
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			if (i == j || rows - i - 1 == j)
			{
				continue;
			}
			if (numbersArr[i][j] % 2 != 0)
			{
				result += numbersArr[i][j];
			}
		}
	}
	cout << "The sum is: " << result;
}

