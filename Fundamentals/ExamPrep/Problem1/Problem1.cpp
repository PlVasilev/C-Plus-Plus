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
	multimap<double, string, greater<double>> result;
	map<string, double> current;
	int num;
	cin >> num;

	double total = 0;

	for (int i = 0; i < num; ++i)
	{
		string item;
		double price;
		double count;
	
		cin >> item >> price >> count;
		string itemName = std::to_string(i) + item;
		double itemTotal = price * count;
		total += itemTotal;
		current[itemName] = itemTotal;
	}

	int counter = 0;

	for (auto pair : current)
	{
		
		result.insert({ pair.second,pair.first });
	}

	cout << "The total sum is: " << total << " lv." << endl;

	for (auto value : result)
	{
		cout << value.second.substr(1) << " " << value.first << endl;
	}

}

