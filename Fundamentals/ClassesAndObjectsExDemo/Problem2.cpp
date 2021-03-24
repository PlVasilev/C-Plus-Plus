#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Country {

private:
	string name;
	string capital;
	int millionsPopulation;

public:

	Country(string name, string capital, int millionsPopulation) :
		name(name),
		capital(capital),
		millionsPopulation(millionsPopulation) {
	}

	bool populationEquals(int millions) { return millionsPopulation == millions; }

	string getData(void) {
		ostringstream ostr;

		ostr << "Country -> " << name << endl
			<< "Capital -> " << capital << endl
			<< "Population(millions) -> " << millionsPopulation;

		return ostr.str();
	}

	void toStream(ostream & ostr) {
		ostr << "Country -> " << name << endl
			<< "Capital -> " << capital << endl
			<< "Population(millions) -> " << millionsPopulation << endl;
	}
};

void Problem2(void) {

	unsigned countriesCount; 

	cout << "How many countries you want to input ?" << endl;
	cin >> countriesCount;

	vector<Country> countries;

	while (countriesCount--) {
		string name;
		string capital;
		int millions;

		cout << "Enter Country ->" << endl;
		cin >> name;
		cout << "Enter Capital ->" << endl;
		cin >> capital;
		cout << "Enter Population ->" << endl;
		cin >> millions;

		countries.push_back(Country(name, capital, millions));
	}

	int millionsToFilter;
	cout << "Which is the populations (millions) that you want to filter ?" << endl;
	cin >> millionsToFilter;

	cout << "The countries with Population " << millionsToFilter << " millions are:" << endl;

	for (vector<Country>::iterator itCountry = countries.begin(); itCountry != countries.end(); itCountry++) {
		
		if (itCountry->populationEquals(millionsToFilter))
			itCountry->toStream(cout);
	}
}