#include <iostream>
#include <list>


using namespace std;

int main()
{

	list<char> charList;

	int countNum;
	cin >> countNum;

	char c;

	while (countNum--) {
		cin >> c;
		charList.push_back(c);
	}

	string numbers;
	string letters;
	string other;

	for (list<char>::iterator it = charList.begin(); it != charList.end(); it++) {
		if (*it >= '0' && *it <= '9') {
			//cout << *it << " ";
			numbers.push_back(*it);
		}
		else (*it >= 'a' && *it <= 'z') {
			letters.push_back(*it);
		}
		else {
			other.push_back(*it);
		}
	}

	cout << numbers << endl;
	cout << letters << endl;
	cout << other << endl;

	return 0;
}