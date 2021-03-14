#include <iostream>
#include <string>

class Person {
	std::string name;
	int age;
public:
	Person(std::string name, int age) : name(name), age(age) {}

	std::string getName() {
		return this->name;
	}
};

int main_04() {
	int sizeVariable;
	std::cin >> sizeVariable;
	int* intArr = new int[sizeVariable] { 42, 13, 255 };
	std::cout << intArr[0] << " " << intArr[1] << " " << intArr[2] << std::endl;

	Person* personPtr = new Person("John", 20);
	// Person* personArr = new Person[3]; // doesn't compile - no default ctor for Person

	std::cout << personPtr->getName() << std::endl;

	// NOTE: missing delete - we are leaking memory
	delete personPtr;
	personPtr = nullptr; // good practice

	return 0;
}