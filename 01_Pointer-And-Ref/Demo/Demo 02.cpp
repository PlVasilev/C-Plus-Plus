#include<iostream>
#include<cmath>

void f() {
}

int main_02() {
	using namespace std;

	// POINTERS
	
	int x = 42;
	auto addressX = &x;
	cout << x << " at " << addressX << endl;

	cout << "f()" << " code at " << &f << endl;

	// NOTE: there are different abs functions (int, double...), so we specify we want the one returning double and accepting 1 double parameter
	double(&absAddress)(double) = abs;
	cout << "abs(double)" << " code at " << absAddress << endl;

	
	 // Referencing and Dereferencing
	
	
	int a = 42, b = 13;
	int* ptr = &a;
	cout << *ptr << endl;

	ptr = &b;
	*ptr = 7;
	cout << b << endl;

	string s = "world";
	string* sPtr = &s;
	sPtr->insert(0, "hello "); // makes s == "hello world"
	cout << *sPtr << endl;
	\

	int number = 42;
	int* ptr1 = &number;
	(*ptr1)++;
	std::cout << *ptr1 << std::endl;

	return 0;
}
