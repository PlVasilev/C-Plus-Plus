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
	// int sum = 0;
	// 
	// string input;
	// cin >> input;
	// 
	// while (input != "Stop")
	// {
	//     int currentNum = atoi(input.c_str()); // string to int
	//      // int currentNum = stoi(input); // string to int
	//     sum += currentNum;
	//     cin >> input;
	// }
	// 
	// cout << sum;


  /*   string name;
	 getline(cin, name);

	 double total = 0.0;
	 double count = 0;
	 bool failed = false;

	 cout.setf(ios::fixed);
	 cout.precision(2);

	 while (count < 12)
	 {
		 double input;
		 cin >> input;
		 if (input >= 4)
		 {
			 count++;
			 total += input;
			 failed = false;
		 }
		 else
		 {
			 if (failed)
			 {
				 break;
			 }
			 failed = true;
		 }
	 }

	 if (count == 12)cout << name << " graduated. Average grade: " << total / count;
	 else cout << name << " has been excluded at " << setprecision(0) << fixed <<  count + 1 << " grade";
		*/

		//-------------------------------------------------------------------------------------------------------------

	 //   int num;
	 //   cin >> num;

	 //   cin.ignore();
	 //   string name;
	 //   getline(cin, name);

	 //   string lastProblem;

	 //   double grade;
	 //   cin >> grade;

	 //   int poorGrades = 0;
	 //   double gradeSum = 0;

	 //   int problems = 0;

	 //  while (name != "Enough")
	 //  {
	 //      problems++;
	 //      gradeSum += grade;

		//   if (grade <= 4)
		//   {
	 //          poorGrades++;
	 //          if (poorGrades >= num)
	 //          {
	 //              break;
	 //          }
		//   }

	 //      cin.ignore();
	 //      getline(cin, name);
	 //      if (name == "Enough")
	 //      {
		//       break;
	 //      }
	 //      lastProblem = name;
	 //      cin >> grade;
	 //  }

	 //  if (poorGrades >= num)
	 //  {
	 //      cout << "You need a break, " << poorGrades << " poor grades.";
	 //  }
		//else
	 //  {
	 //      cout << "Average score: " << setprecision(2) << fixed << gradeSum/problems << endl;
	 //      cout << "Number of problems: " << problems << endl;
	 //      cout << "Last problem: " << lastProblem << endl;
	 //  }


	//-------------------------------------------------------- Change count
	//double change;
	//cin >> change;

	//int count = 0;

	//change *= 100;

	//int totalChange = change;

	//count += (totalChange / 200);
	//totalChange %= 200;

	//count += (totalChange / 100);
	//totalChange %= 100;

	//count += (totalChange / 50);
	//totalChange %= 50;

	//count += (totalChange / 20);
	//totalChange %= 20;

	//count += (totalChange / 10);
	//totalChange %= 10;

	//count += (totalChange / 5);
	//totalChange %= 5;

	//count += (totalChange / 2);
	//totalChange %= 2;

	//count += totalChange ;


	//cout << count;

	int x, y;
	cin >> x >> y;

	int totalPieces = x * y;

	do
	{
		string taken;
		cin >> taken;
		if (taken == "STOP") break;
		
		totalPieces -= stoi(taken);
	}
	while (totalPieces >= 0);

	if (totalPieces >= 0)
	{
		cout << totalPieces << " pieces are left.";
	}
	else
	{
		cout << "No more cake left! You need " << totalPieces * -1 << " pieces more.";
	}
}

