#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>
#include "cmath"
#include <chrono>
#include <string>

using namespace std;

int main()
{
	unsigned long long num;
	num = 5; num = -5; num = 5L; num = 5ULL; num = 0xF;

	double numd;
	numd = .42; numd = 0.42; numd = 42e-2;
	float floatNum;
	floatNum = .42f; floatNum = 0.42f; floatNum = 42e-2f;

	cout << -42 << " " << 052 << " " << 0x2a << " " << 0x2A << endl
		<< 0.42 << " " << .42f << " " << 42e-2 << endl;
	
}


