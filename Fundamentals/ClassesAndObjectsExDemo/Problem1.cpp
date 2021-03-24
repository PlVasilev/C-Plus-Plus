#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Student {

private:
	string name;
	string surname;
	int age;
	double vote;

public:
/*	Student() : 
		age(0), 
		vote(0) {
	}*/

	Student(string name_, string surname_, int age_, double vote_) :
		name(name_),
		surname(surname_),
		age(age_),
		vote(vote_) {
	}

	// Setters
	// void setName(string name_) { name = name_; }
	// void setSurname(string surname_) { surname = surname_;  }
	// void setAge(int age_) { age = age_; }
	// void setVote(int vote_) { vote = vote_; }

	double getVote(void) { return vote; }

	string getData(void) {
		ostringstream ostr;

		ostr << "Name -> " << name << " " << surname << endl
			<< "Age -> " << age << endl
			<< "Vote -> " << vote;

		return ostr.str();
	}
};

void Problem1(void) {

	unsigned studentCount; 

	cout << "How many students you want to input ?" << endl;
	cin >> studentCount;

	vector<Student> students;

	while (studentCount--) {
		string name;
		string surname;
		int age;
		double vote;

		cout << "Enter name: " << endl;
		cin >> name;
		cout << "Enter surname: " << endl;
		cin >> surname;
		cout << "Enter age: " << endl;
		cin >> age;
		cout << "Enter vote (the vote can be with decimal point): " << endl;
		cin >> vote;

		students.push_back(Student(name, surname, age, vote));
	}

	double minVote;
	cout << "Which is the minimal vote that you would like to filter?" << endl;
	cin >> minVote;

	cout.precision(1);
	cout << "The students with MIN vote -> " << minVote << " are:" << endl;

	for (vector<Student>::iterator itStud = students.begin(); itStud != students.end(); itStud++) {
		
		if (itStud->getVote() >= minVote)
			cout << itStud->getData() << endl;
	}
}