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
	multimap<double, string, greater<int>> result;
	vector<vector<string>> input;
	vector<string> lines;
	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		vector<string> line;
		if (i == 0)std::cin.ignore();
		string line3;
		getline(std::cin, line3);
		std::istringstream iss(line3);
		string enterNumber;
		while (iss >> enterNumber)
		{
			line.push_back(enterNumber);
		}
		input.push_back(line);
		lines.push_back(line3);
	}

	for (int i = 0; i < input.size(); ++i)
	{
		int x = 0;
		int a = stoi(input[i][0]);
		int b = stoi(input[i][2]);
		if (input[i][1] == "+")
		{
			x = a + b;
		}
		else if (input[i][1] == "-")
		{
			x = a - b;
		}
		else if (input[i][1] == "*")
		{
			x = a * b;
		}
		else if (input[i][1] == "/")
		{
			x = a / b;
		}
		else if (input[i][1] == "%")
		{
			x = a % b;
		}
		result.insert({ x, lines[i] });
	}
	for (auto value : result) cout << value.second << endl;
	
}

