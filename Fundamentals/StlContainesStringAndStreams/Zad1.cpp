#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;


int main_zad1()
{
	stack<string> stack;

	while (1) {
		string word;
		cin >> word;
		if (word == "end")
			break;
		stack.push(word);
	}

	while (stack.size())
	{
		cout << stack.top() << " ";
		stack.pop();
	}

	return 0;
}

