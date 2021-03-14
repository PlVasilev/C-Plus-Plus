#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H
#include <string>
#include <vector>
using namespace std;


vector<string> operator+(const vector<string>& a, const vector<string>& b) {
	vector<string> result;
	for (size_t i = 0; i < a.size(); i++)
	{
		result.push_back(a[i] + " " + b[i]);
	}
	return result;	
}

#endif // !SUMOFVECTORS_H
