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
	int a, b, c;
	cin >> a >> b >> c;

	for (int i = 1; i <= a; ++i)
	{
		for (int j = 1; j <= b; ++j)
		{
			for (int k = 1; k <= c; ++k)
			{
				if (i %2 == 0 && k % 2 == 0 && (j == 2 || j == 7 || j == 3 || j == 5))
				{
					cout << i << " " << j << " " << k << endl;
				}
			}
		}
	}
}
	


