
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;

vector<string> getShiftedSentence()
{

	typedef vector<string> Sentence;
	string line3; getline(cin, line3);
	istringstream lineStream(line3);
	Sentence sentence;
	string currentNumber;
	while (lineStream >> currentNumber) sentence.push_back(currentNumber);
	int num;
	cin >> num;
	vector<string> result;

	for (int i = sentence.size() - num; i < sentence.size(); ++i)
	{
		result.push_back(sentence[i]);
	}
	for (int i = 0; i < sentence.size() - num; ++i)
	{
		result.push_back(sentence[i]);
	}

	return result;
}

double getDistance()
{

	string line3; getline(cin, line3);
	string line4; getline(cin, line4);
	istringstream lineStream(line3);
	istringstream lineStream2(line4);
	vector<double> numbers;
	vector<double> numbers2;
	int currentNumber;
	while (lineStream >> currentNumber) numbers.push_back(currentNumber);
	while (lineStream2 >> currentNumber) numbers2.push_back(currentNumber);

	double x = (numbers[0] - numbers2[0]) * (numbers[0] - numbers2[0]);
	double y = (numbers[1] - numbers2[1]) * (numbers[1] - numbers2[1]);

	double result = sqrt(((numbers[0] - numbers2[0]) * (numbers[0] - numbers2[0])) + ((numbers[1] - numbers2[1]) * (numbers[1] - numbers2[1])));
	return result;
}

class Sale {
public:
	string town;
	string product;
	double price;
	double quantity;

	Sale(string town_, string product_, double price_, double quantity_)
	{
		town = town_;
		product = product_;
		price = price_;
		quantity = quantity_;
	}

	double getTotaSales() {
		return price * quantity;
	}
};

int main()
{
	// vector<string> reWorked = getShiftedSentence();
	// for (vector<string>::iterator i = reWorked.begin(); i != reWorked.end(); i++) {
	// 	cout << *i << endl;
	// }

	// double result = getDistance();
	// cout << setprecision(3) << fixed << result;

	int num;
	cin >> num;
	cin.ignore();


	vector<Sale> sales;

	for (int i = 0; i < num; ++i)
	{
		string line3; getline(cin, line3);
		istringstream lineStream(line3);
		vector<string> strings;
		vector<double> doubles;
		string current;
		while (lineStream >> current)
		{
			if (atof(current.c_str()))
			{
				doubles.push_back(atof(current.c_str()));
			}
			else
			{
				strings.push_back(current);
			}
		}
		Sale currentSale = Sale(strings[0], strings[1], doubles[0], doubles[1]);
		sales.push_back(currentSale);
	}

	map<string, double> result;
	for (auto sale : sales) result[sale.town] += sale.getTotaSales();

	for (auto value : result) cout << value.first << " -> " << setprecision(2) << fixed << value.second << endl;

	return 0;
}



