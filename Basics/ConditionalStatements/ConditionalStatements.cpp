#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <chrono>


using namespace std;

int main()
{

	// -------------------------- SET FILL
	//int num1, num2, num3;
	//cin >> num1 >> num2 >> num3;
	//
	//int sum = num1 + num2 + num3;
	//int minutes = sum / 60;
	//int seconds = sum % 60;
	//cout << minutes << ":" << setfill('0') << setw(2) << seconds;


	// -------------------------- CAST
	/*int num;
	cin >> num;
	double bonus = 0;

	if (num % 2 == 0){bonus += 1;}
	else if (num % 5 == 0){bonus += 2;}

	if (num <= 100){bonus += 5;	}
	else if(num <= 1000){bonus += static_cast<double>(num) * 0.2;}
	else { bonus += static_cast<double>(num) * 0.1; }
	cout << bonus << endl;
	cout << bonus + num << endl;*/

	//------------------------------- ABS
	//double num1, num2, num3;
	//cin >> num1 >> num2 >> num3;
	//
	//const double result = (num2 * num3) + ( floor(num2 / 15) * 12.5);
	//
	//cout.setf(ios::fixed);
	//cout.precision(2);
	//
	//if (result < num1){cout << "Yes, he succeeded! The new world record is " << setprecision(2) << fixed << result << " seconds." << endl;}
	//else if(result > num1){cout << "No, he failed! He was " << setprecision(2) << fixed << abs(num1 - result) << " seconds slower." << endl;}
	//else{cout << "No, he failed! He was " << setprecision(2) << fixed << abs(num1 - result) << " seconds slower." << endl;}

	double num1, num2, num3;
	cin >> num1 >> num2 >> num3;

	//cout.setf(ios::fixed);
	//cout.precision(0);

	double socialScolarshitp = 0;
	double excelentScolarshitp = 0;

	if (num1 < num3 && num2 >= 4.5)
	{
		socialScolarshitp = num3 * 0.35;
	}
	if (num2 >= 5.5)
	{
		excelentScolarshitp = num2 * 25;
	}

	if (socialScolarshitp == 0 && excelentScolarshitp == 0)
	{
		cout << "You cannot get a scholarship!";
	}
	else
	{
		if (socialScolarshitp > excelentScolarshitp)
		{
			cout << "You get a Social scholarship " << floor(socialScolarshitp) << " BGN" << endl;
		}
		else
		{
			cout << "You get a scholarship for excellent results " << floor(excelentScolarshitp) << " BGN" << endl;
		}
	}

}


