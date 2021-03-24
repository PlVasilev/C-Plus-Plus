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
	cout.setf(ios::fixed);
	cout.precision(0);

	int n;
	cin >> n;

	int salary;
	cin >> salary;

	for (int i = 0; i < n; i++)
	{
		string num;
		cin >> num;
		if (num == "Facebook") salary-=150;
		if (num == "Instagram") salary -= 100;
		if (num == "Reddit") salary -= 50;
		if (salary <= 0)
		{
			cout << "You have lost your salary.";
			return 0;
		}
	}
	cout << salary;
}


