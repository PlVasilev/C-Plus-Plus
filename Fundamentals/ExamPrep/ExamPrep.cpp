#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <list>
#include <math.h> 
using namespace std;

class Student {
private:
	string h;
	string m;
	double s;

public:
	Student(string h_, string m_, double s_)
	{
		h = h_;
		m = m_;
		s = s_;
	}

	double getGrade(void) { return s; }

	void GetStudent()
	{
		cout << h << " " << m << " " << s << endl;
	}
};

class Time {
private:
	int h;
	int m;
	int s;

public:
	Time(int h_, int m_, int s_)
	{
		h = h_;
		m = m_;
		s = s_;
	}

	void GetTime()
	{
		cout << h << endl;
		cout << h * 60 + m << endl;
		cout << h * 3600 + m * 60 + s << endl;
	}
};

class Rectangle {
private:
	int x;
	int y;

public:
	Rectangle(int x_, int y_)
	{
		x = x_;
		y = y_;
	}

	int getX(void) { return x; }
	int getY(void) { return y; }
	void setX(int nom_) { x = nom_; }
	void setY(int denom_) { y = denom_ != 0 ? denom_ : 1; }
	void Print() { cout << toString(); }

	void GetAreaAndParameter()
	{
		cout << x * y << endl;
		cout << 2 * x + 2 * y << endl;
	}


	string toString() {
		ostringstream str;
		str << x << '/' << y;
		return str.str();
	}
};

int main()
{
	//	int num;
	//	cin >> num;
	//	cin.ignore();
	//	string line3; getline(cin, line3);
	//	istringstream lineStream(line3);
	//	list<int> numbers;
	//	int currentNumber;
	//	while (lineStream >> currentNumber) numbers.push_back(currentNumber);
	//	numbers.sort(std::greater<int>());
	//	for (list<int>::iterator i = numbers.begin(); i != numbers.end(); i++)
	//	{
	//		cout << *i << " ";
	//	}
	//	cout << endl;


	//	int num;
	//	cin >> num;
	//	cin.ignore();
	//	string line3; getline(cin, line3);
	//	istringstream lineStream(line3);
	//	set<char> chars;
	//	set<char> nums;
	//	set<char> letters;
	//	set<char> others;
	//	char currentNumber;
	//	while (lineStream >> currentNumber) chars.insert(currentNumber);
	//	
	//	for (set<char>::iterator i = chars.begin(); i != chars.end(); i++)
	//	{
	//		if (*i >= 48 && *i <= 57) nums.insert(*i);
	//		else if (*i >= 97 && *i <= 122) letters.insert(*i);
	//		else others.insert(*i);
	//	}
	//	if (!nums.empty())
	//	{
	//		for (set<char>::iterator i = nums.begin(); i != nums.end(); i++) cout << *i << " ";
	//		cout << endl;
	//	}
	//	if (!letters.empty())
	//	{
	//		for (set<char>::iterator i = letters.begin(); i != letters.end(); i++) cout << *i << " ";
	//		cout << endl;
	//	}
	//	if (!others.empty())
	//	{
	//		for (set<char>::iterator i = others.begin(); i != others.end(); i++) cout << *i << " ";
	//	} 

	// int x, j;
	// cin >> x >> j;
	// Rectangle rectangle(x,j);
	// rectangle.GetAreaAndParameter

	// int h, m, s;
	// cin >> h >> m >> s;
	// Time time(h, m, s);
	// time.GetTime();

	int num;
	cin >> num;
	vector<Student> students;

	for (int i = 0; i < num; ++i)
	{
		string h, m;
		cin >> h >> m;
		double s;
		cin >> s;
		Student student(h, m, s);
		students.push_back(student);
	}
	double result = 0.0;
	for (auto value : students) {
		value.GetStudent();
		result += value.getGrade();
	}
	cout << result / students.size();
}



