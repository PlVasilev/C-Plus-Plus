\
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	typedef vector<int> MyVector;

	// size_t and size_type
	//  Alias of one of the integer types E.g. unsigned long int or unsigned long long int
	//  Able to represent the size ofany object in bytes E.g. sizeof() returns size_t
	//  Each STL container offersa similar::size_type
	//  A good practice is to use it instead of int for sizes, positions, etc
	MyVector elements;
	for (vector<int>::size_type i = 0; i < elements.size(); i++) {
		cout << elements[i] << endl;
	}

	//											ITERATORS
	//	STL Iterators
	//		operator++ - moves iterator to the next element
	//		operator* -accesses the element
	//		operator-> - same as operator. on the element
	//		Each container has an iterator
	//		Each container has begin() and end() iterators
	
	//Using Iterators with Vectors
	//	Almost the same as using indexes
	//		To walk over a vector :
	//		Start from begin(), move with ++ until you reach end()
	//		Access the current element with*

	MyVector elements1{ 42, 13, 69 };
	for (MyVector::iterator i = elements1.begin(); i != elements1.end(); i++) {
		cout << *i << endl;
	}
	// Equivalent code
	for (vector<int>::size_type i = 0; i < elements1.size(); i++) {
		cout << elements1[i] << endl;
	}

	//Example: Change each element in the vector by dividing it by 2
	vector<int> numbers{ 42, 13, 69 };
	for (auto i = numbers.begin(); i != numbers.end(); i++) {
		*i /= 2;
	}
	// Equivalent code
	for (int i = 0; i < numbers.size(); i++) {
		numbers[i] /= 2;
	}

	//Example 2
	vector<string> words{ "the", "quick", "purple", "fox" };
	for (vector<string>::iterator i = words.begin(); i != words.end(); i++) {
		cout << *i << ": " << i->size() /*(*i).size()*/ << endl;
	}
	// Equivalent code
	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << ": " << words[i].size() << endl;
	}

	// Why Use Iterators?
	//  Vectors may not need iterators, because they have indexes
	//	i.e.they have sequential elements accessible by operator[]
	//	Not all containers have indexes
	//	Only std::array, std::vector& std::deque have indexes
	//	The other containers don't offer access by index
	//	Iterators work on all containers, abstract - away container details
	//	Doesn't matter what container you iterate, code is the same

	//				LINKED LIST	= std::list
	// Represents elements connected to each other in a sequence
	// Each element connets to the previous and next element.  Like Christmas lights.
	// All element access is done with iterators
	//	Can add or remove elements anywhere in O(1) time
	//	Requires iterator to where an element should be added / removed
	//	push_back(), push_front(), insert(), size(), etc.
	list<int> values;
	std::list<string> names;

	//	Container Adaptors
	//  Wrap a container(e.g.vector) with a different interface
	//	Allow you to express intentions better
	//	Make code more abstractand focused on the task, not the code

	// STL Adapters for common Computer Science data structures:
	std::stack<int> stack; // last - in, first - out(LIFO) data structure
	std::queue<int> queue; // first - in, first - out(FIFO) data stucture
	std::priority_queue<int> priority; // data structure that gives quick access to the "highest priority item"

	// std::stack
	//  Represents a container(a deque by default) working like a stack
	//  	A stack is a “last - in, first - out structure" (LIFO)
	//  	Imagine a pile of dishes– the last dish you put is the first you can remove
	//  	Access to elements other than top() is not provided
	// top() gets the top
	// pop() removes top
	// push(T) adds to top
	// Stack Example: "Browser History" Back

	// std::queue
	//  Represents a container(deque by default) working like a queue
	//	A queue is a "first-in, first-out" structure(FIFO)
	//	Imagine a line at a store – first person in the line is the first to get out
	//	Access to elements other than front() is not provided
	// front() gets first
	// pop() removes first 
	// push(T) adds to back
	// Queue Example: "Browser History" Forward

	// std::priority_queue
	//  Represents a queue, but elements are ordered by priority
	//	By default, "larger" elements have higher priority
	//	Imagine a queue at a hospital's emergency room – Patients with more serious cases treated BEFORE those with less serious ones
	//	Higher priority elements move in front of lower priority ones
	//	Getting top - priority element is O(1), insertion is log(N)
	//	To get top - priority element use top() (instead of front())

}


