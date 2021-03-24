#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

int main()
{
	//string firstname;
	//cin >> firstname;
	//
	//string lastname;
	//cin >> lastname;
	//
	//int age;
	//cin >> age;
	//
	//string town;
	//cin >> town;
	//
	//cout << "You are " << firstname << " "  << lastname << ", a " << age << "-years old person from " << town << ".";
	//return 0;

	//-----------------------------      Precession
	//double area;
	//cin >> area;
	//double totalPrice = area * 7.61;
	//const double discount = totalPrice * 0.18;
	//double discountedPrice = totalPrice - discount;
	//
	//cout << "The final price is: " << setprecision(2) << fixed << discountedPrice << " lv." << endl;
	//cout << "The discount is: " << setprecision(2) << fixed << discount << " lv.";
	//
	//double usd;
	//cin >> usd;
	//
	//double bgn = usd * 1.79549;
	//
	//cout.setf(ios::fixed);
	//cout.precision(2);
	//
	//cout << bgn;

	//----------------------------           Math round
	//double radians;
	//cin >> radians;
	//
	//double degrees = round(radians * 180 / M_PI);
	//
	//cout << degrees;

	//---------------------------             Multiple declarations
	//double x1, y1, x2, y2;
	//cin >> x1 >> y1 >> x2 >> y2;
	//
	//double width = abs(x1 - x2);
	//double height = abs(y1 - y2);
	//
	//double parameter = width * 2 + height * 2;
	//double face = width * height;
	//
	//cout << setprecision(2) << fixed << face << endl;
	//cout << setprecision(2) << fixed << parameter;

	//---------------------------             Floor
	//double length;
	//cin >> length;
	//
	//double width;
	//cin >> width;
	//
	//double wardrobeSide;
	//cin >> wardrobeSide;
	//
	//double freeSpace = (length * 100 * width * 100) - (wardrobeSide * 100 * wardrobeSide * 100) - ((length * 100 * width * 100) * 0.1);
	//double dancers = floor(freeSpace / (40 + 7000));
	//
	//cout << dancers;

	double whiskeyPrice, beerLit, wineLit, rakiaLit, whiskeyLit;
	cin >> whiskeyPrice >> beerLit >> wineLit >> rakiaLit >> whiskeyLit;

	double beerCost = beerLit * (whiskeyPrice/2 * 0.2);
	double wineCost = wineLit * (whiskeyPrice/2 * 0.6);
	double rakiaCost = rakiaLit * (whiskeyPrice * 0.5);
	double whiskeyCost = whiskeyLit * whiskeyPrice;

	cout << setprecision(2) << fixed << beerCost + wineCost + rakiaCost + whiskeyCost;
}


