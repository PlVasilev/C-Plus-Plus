#include<iostream>
#include<string>
using namespace std;

class Person {
public:
    string name;
    int age = 0;
    double heightMeters = 0;

    Person(string name, int age, double heightMeters) {
        this->name = name;
        this->age = age;
        this->heightMeters = heightMeters;
    }

    // Correct way (for using constructor body) - explicitly accessing the fields through the "this" pointer
    //Person(string name, int age, double heightMeters) {
    //    this->name = name;
    //    this->age = age;
    //    this->heightMeters = heightMeters;
    //}
};

void printPersonInfo(Person person) {
    cout << "name: " << person.name << ", age: " << person.age
        << ", height: " << person.heightMeters
        << endl;
}

int main() {
    Person Ary0("Ary O'usure", 42, 1.3);
    printPersonInfo(Ary0);

    return 0;
}
