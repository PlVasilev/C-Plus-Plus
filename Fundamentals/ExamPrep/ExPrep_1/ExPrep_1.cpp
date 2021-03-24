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
	int num;
	cin >> num;
	vector<string> words;
	vector<vector<string>> sentences;
	vector<vector<string>> results;

	cin.ignore();

	for (int i = 0; i < num; ++i)
	{
		string line3; getline(cin, line3);
		istringstream lineStream(line3);
		string word;
		while (lineStream >> word) words.push_back(word);
	}

	vector<string> sentience;
	for (int i = 0; i < words.size(); ++i)
	{
		string item = words[i];

		if (i == words.size() - 1 || item == ".")
		{
			sentience.push_back(item);
			sentences.push_back(sentience);
			sentience.clear();
		}
		else sentience.push_back(item);
	}
	for (auto cs : sentences)
	{
		vector<string> result;
		for (auto c : cs)
		{
			bool isDuplicate = false;

			for (auto word : result)
			{
				if (word == c)
				{
					isDuplicate = true;
					break;
				}
			}
			if (isDuplicate) continue;
			result.push_back(c);
		}
		results.push_back(result);
	}
	for (auto cses : results)
	{
		for (auto cse : cses)
		{
			cout << cse << " ";
		}
	}
}


