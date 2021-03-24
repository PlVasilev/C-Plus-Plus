#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

bool checkBrackets(const string & bracketsString) {
	
	stack<char> brackets;
	string::const_iterator itS = bracketsString.begin();

	while (itS != bracketsString.end()) {

		// read a bracket
		char bracket;
		bracket = *itS; 

		if (bracket == '(' || // if this is OPEN bracket { [ (
			bracket == '[' ||
			bracket == '{'
			) {
				// check if the bracket level is correct
				if (brackets.size() && brackets.top() < bracket)
					return false; // incorrect bracket level

				// push bracket in our stack
				brackets.push(bracket);
		}
		else { 			// if this is a CLOSING bracket ) ] }

			// the stack cannot be empty!
			if (brackets.size() == 0)
				return false;

			// check if the closing bracket matches top of the stack
			switch (brackets.top())
			{
				case '(': 
					if (bracket != ')') 
						return false;
					break;
				case '[':
					if (bracket != ']') 
						return false;
					break;
				case '{':
					if (bracket != '}')
						return false;
					break;
				default: 
					return false;
			}
			
			brackets.pop(); // pop from bracket stack
		}

		itS++; // next symbol
	}

	return brackets.size() == 0;
}

int main_zadStream4()
{
	string brackets;
	cin >> brackets;

	if (checkBrackets(brackets))
		cout << "valid";
	else
		cout << "invalid";
	
	return 0;
}

