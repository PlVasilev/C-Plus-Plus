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

class Coffee {

private:
	string name;
	double price;
	double rating;
	

public:
	/*	Student() :
			age(0),
			vote(0) {
		}*/

	Coffee(string name_, double price_, double rating_) :
		name(name_),
		price(price_),
		rating(rating_)
	{
		if (rating_ >= 4 && rating_ <= 5.99)
		{
			price = price_ * 0.9;
		}
	}

	void addNew();
	void getRating();
	void getPrice();

	void changePrice();
	void deleteDrink();



};

int main()
{
	vector<Coffee> menu;

	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		string name;
		double price1;
		double rating2;

		cin.ignore();
		getline(cin, name);

		cin >> price1 >> rating2;

		if (rating2 < 4)
		{
			continue;
		}
		if (rating2 >= 4 && rating2 <= 5.99)
		{
			price1 = price1 * 0.9;
		}
		cout << name << " " << price1 << endl;
		menu.push_back(Coffee(name, price1, rating2));
	}

	if (menu.empty())
	{
		cout << "The menu is empty";
	}
}


