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
#include <stack>

using namespace std;

int main()
{
	int num;
	cin >> num;

	vector<string> input;

	for (int i = 0; i < num; ++i)
	{
		if (i == 0)std::cin.ignore();
		string line;
		getline(std::cin, line);
		input.push_back(line);
	}

	string number;
	cin >> number;

	for (auto cs : input)
	{
		int width = cs.size() / 10;
		string str0 = cs.substr(0 * width, width);
		string str1 = cs.substr(1 * width, width);
		string str2 = cs.substr(2 * width, width);
		string str3 = cs.substr(3 * width, width);
		string str4 = cs.substr(4 * width, width);
		string str5 = cs.substr(5 * width, width);
		string str6 = cs.substr(6 * width, width);
		string str7 = cs.substr(7 * width, width);
		string str8 = cs.substr(8 * width, width);
		string str9 = cs.substr(9 * width, width);

		for (auto digit : number)
		{
			switch (digit)
			{
			case '0': cout << str0; break;
			case '1': cout << str1; break;
			case '2': cout << str2; break;
			case '3': cout << str3; break;
			case '4': cout << str4; break;
			case '5': cout << str5; break;
			case '6': cout << str6; break;
			case '7': cout << str7; break;
			case '8': cout << str8; break;
			case '9': cout << str9; break;
			default: break;
			}
		}
		cout << endl;
	}
}


