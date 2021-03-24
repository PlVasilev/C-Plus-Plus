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
	vector<vector<double>> numbersArr;
	int rows, cols;
	cin >> rows >> cols;

	for (int i = 0; i < rows; ++i)
	{
		vector<double> numbers;
		if (i == 0)std::cin.ignore();
		string line3;
		getline(std::cin, line3);
		std::istringstream iss(line3);
		int enterNumber;
		while (iss >> enterNumber)
		{
			numbers.push_back(enterNumber);
		}
		numbersArr.push_back(numbers);
	}
	int size, target;
	cin >> size >> target;

	vector<int> result;
	for (int i = 0; i <= rows - size; ++i)
	{
		for (int j = 0; j <= cols - size; ++j)
		{
			double currentResult = 0;

			for (int k = 0; k < size; ++k)
			{
				for (int l = 0; l < size; ++l)
				{
					currentResult += numbersArr[i + k][j + l];
				}
			}
			if (currentResult >= target)
			{
				int a = floor(currentResult / (size * size));
				result.push_back(a);
			}
		}
	}
	sort(result.begin(), result.end());
	for (auto value : result)
	{
		cout << value << " ";
	}
}


