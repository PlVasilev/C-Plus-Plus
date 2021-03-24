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
#include <stack>
using namespace std;

class Person
{
	
public:
	void setName(string & name)
	{
		_name = name;
	}

	string getName()
	{
		return _name;
	}
private:

	string _name;
};

void foo(int second, int first = 10)
{
	
}

int main()
{
	
	string name = "Manol";
	cout << name + "20";
	cout << name.append("20");

}


