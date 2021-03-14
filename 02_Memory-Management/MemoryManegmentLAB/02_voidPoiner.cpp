#include <iostream>
using namespace std;

void print(int n) {
	std::cout << n << std::endl;
}

void pitfallCasting(void) {

	char letter1 = 'a', letter2 = 'b', letter3 = 'c', letter4 = 'd';
	int* letter4Ptr = (int*)&letter1;

	cout << letter1 << letter2 << letter3 << letter4 << endl;

	*letter4Ptr = 842281524;

	cout << letter1 << letter2 << letter3 << letter4 << endl;
}

void castingPointers() {
	char letter = 'A';

	void* voidPtr = &letter;
	char* charPtr = &letter;

	char* cStyleCastPtr = (char*)voidPtr;
	int* badCast = (int*)charPtr;

	cout << *cStyleCastPtr << endl; // prints 'A'
	cout << *badCast << endl; // undefined behavior - takes sizeof(int) bytes starting from 'A' and prints resulting number - could cause a memory error if those bytes are outside the program's memory

	char* staticCastPtr = static_cast<char*>(voidPtr); // for void pointer, static_cast is equivalent to C-Style cast
	cout << *staticCastPtr << endl;
	//int* badStaticCastWontCompile = static_cast<int*>(charPtr); // static_cast here checks type and prevents compilation (uncomment to see compilation error)

}

int myStaticInt = 45; 

int main_02() {
	using namespace std;

	int number = 42;
	char cStr[] = "I'm a C-String";
	const char * otherCStr = "I'm another C-String";

	int* numberPtr = &number;
	cout << numberPtr << endl;
	*numberPtr = 52;
	cout << *numberPtr << endl;
	void* p;

	p = numberPtr;
	cout << p << endl;

	p = &number;
	cout << p << endl;

	cout << p << endl;

	p = cStr;
	cout << cStr << " " << p << endl; // cStr will be printed as a string, p as an address

	const void* pconst = otherCStr; // pointer to const object requires "const void *"
	cout << otherCStr << " " << pconst << endl; // otherCStr will be printed as a string, p as an address

	p = print;
	cout << p << endl; // address to the function

	// pitfallCasting();


	string s = "world";
	string* sPtr = &s;
	*sPtr = *sPtr + " 33";
	cout << *sPtr << endl;
	sPtr->insert(0, "hello "); // makes s == "hello world"
	cout << *sPtr << endl;

	castingPointers();

	return 0;
}