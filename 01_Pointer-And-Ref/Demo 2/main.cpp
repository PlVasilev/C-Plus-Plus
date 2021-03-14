#include<iostream>
#include<string>

#include "Node.h"
#include "FollowPointers.h"

int main() {
	using namespace std;

	int p = 5; // int variable
	int* pPointer = &p; // pointer to int
	int*& pPointerRef = pPointer; // reference to pointer to int

	// Initialize a single linked list consisting of nodes[0] => nodes[3] ==> nodes[2] ==> nodes[4]
	Node nodes[]
	{
		Node(0, nullptr),
		Node(1, nullptr),
		Node(2, nullptr),
		Node(3, nullptr),
		Node(4, nullptr)
	};
	nodes[0].next = &nodes[3];
	nodes[3].next = &nodes[2];
	nodes[2].next = &nodes[4];
	// end of initialization

	cout << getSumFrom(&nodes[0]) << endl;

	return 0;
}
