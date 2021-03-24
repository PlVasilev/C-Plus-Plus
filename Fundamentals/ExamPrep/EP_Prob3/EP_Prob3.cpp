#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <list>
#include <math.h> 
#include <stack>
using namespace std;

int main()
{
	int num;
	cin >> num;
	cin.ignore();

	vector<pair<string, int>> pepi;
	vector<pair<string, int>> mimi;

	int index = 0;
	for (int i = 0; i < num; ++i)
	{
		string input, input2;
		int minutes;
		cin >> input >> input2 >> minutes;
		if (input == "Pepi")
		{
			pepi.push_back({ input2 ,minutes });
		}
		else
		{
			mimi.push_back({ input2 ,minutes });
		}

	}
	int allTime;
	cin >> allTime;

	for (int i = 0; i < allTime; ++i)
	{
		bool idle = true;
		for (auto& value : pepi)
		{
			
			if (value.second != 0)
			{
				int result = --value.second;
				value.second = result;
				cout << "Pepi processing " << value.first << endl;
				idle = false;
				break;
			}
		}
		if (idle)
		{
			cout << "Pepi Idle" << endl;
		}
		idle = true;
		for (auto& value : mimi)
		{
			
			if (value.second != 0)
			{
				int result = --value.second;
				value.second = result;
				cout << "Mimi processing " << value.first << endl;
				idle = false;
				break;
			}
			
		}
		if (idle)
		{
			cout << "Mimi Idle" << endl;
		}
	}
}


