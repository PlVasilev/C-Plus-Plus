#include<iostream>
#include<string>
using namespace std;

class Person {
    
    class Body {
    public:
        double heightMeters;
        double weightKgs;

        Body(double heightMeters, double weightKgs) :
            heightMeters(heightMeters),
            weightKgs(weightKgs) {
        }
    };

public:
    string name;
    int age = 0;
    Body body;

    Person(string name, int age, double heightMeters, double weightKgs) :
        name(name),
        age(age),
        body(heightMeters, weightKgs) {
    }

    Person() : 
        body(1,1),
        name("unknown") {

    }
   
    void makePersonOlder(int years);

    void printPersonInfo() {
        cout << "name: " << this->name << ", age: " << this->age
            << ", height: " << this->body.heightMeters << ", weight: " << this->body.weightKgs
            << endl;
    }
};

void Person::makePersonOlder(int years) {
    this->age += years;
}

int main() {
    Person person("Met Hods", 42, 1.82, 82.3);
    
    Person* persDef1 = new Person;
    Person* persDef2 = new Person();

    persDef1->printPersonInfo();
    persDef2->printPersonInfo();

    delete persDef1;
    delete persDef2;

    person.printPersonInfo();

    Person* personPointer = &person;
    personPointer->makePersonOlder(1);
    personPointer->printPersonInfo();

    return 0;
}
