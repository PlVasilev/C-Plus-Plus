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

	/*cin.ignore();
	string fruit;
	getline(cin, fruit);

	cout << minArrive - minstart << setfill('0') << setw(2) << " minutes after the start";

	cout << num1 << " " << oparator << " " << num2 << " = " << setprecision(2) << fixed << static_cast<double>(num1) / num2;
   */

   /*cout.setf(ios::fixed);
   cout.precision(0);*/

	string year;
	cin >> year;

	int p, h;
	cin >> p >> h;

	double result = year == "leap" ?  floor((((48 - h) * 0.75) + h + (p * (2.0/3))) * 1.15)   :  floor((((48 - h) * 0.75) + h + (p * (2.0/3))));

	cout << result;
}


