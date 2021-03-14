#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// template <typename T>
std::vector<std::string>& operator<<(vector<string>& v, const string& s)
{
    v.push_back(s);
    return v;
}



std::string operator+(const string& s, const int& i)
{
	std::ostringstream os;
	os << s << i;
	return os.str();
}



ostream& operator<<(ostream& os, const vector<string>& v)
{
	for (auto line: v)
	{
		os << line << endl;
	}
	return os;
}

#endif // !OPERATORS_H
