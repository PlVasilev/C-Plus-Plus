#include <iostream>
#include <list>

using namespace std;

//
// Another solution, which implements sorting altorythm: https://pastebin.com/g0Ux6Ls7
//

/*

5
1 2 3 4 5

3
190 250 1000

5
2 6 4 3 7

*/
int main()
{
	unsigned number;
	cin >> number;

	list<int> myList;
	while (number) {
		int current;
		cin >> current;
		
		if (current < 0)
			continue;

		// search where we need to insert our element, so we can
		// ensure the list remains sorted!
		list<int>::iterator it = myList.begin();
		for (; it != myList.end(); it++) {
			if (current > *it)
				break;
		}

		myList.insert(it, current); // works OK even when it == list.end()

		number--;
	}

	for (list<int>::iterator it = myList.begin(); it != myList.end(); it++) {
		cout << *it << " ";
	}
	return 0;

}