#include <iostream>
#include <string>
#include <utility>
#include <map>
using namespace std;


int main_std_map() {

    map<string, int> cityPopulations =
    {
       {"Gabrovo", 58950},
		{"Sofia", 1307376},
       {"Melnik", 385}
    };

    cityPopulations["Sofia"]++;
    cityPopulations["Veliko Tarnovo"] = 72938;
    cityPopulations.insert({ "Pliska", 0 });
    cityPopulations.insert({ "Pliska", 370 }); // exception

    map<string, int>::iterator it;
    for (it = cityPopulations.begin(); it != cityPopulations.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    cout << endl;

    // "Pliska" isn't really a city, it's an ancient settlement, let's remove it
    cityPopulations.erase("Pliska");

    for (pair<string, int> element : cityPopulations)
    {
        cout << element.first << " " << element.second << endl;
    }

    cout << endl;

    cout << "Enter a city name to see it's population:" << endl;
    string searchCityName;
    getline(cin, searchCityName);

    map<string, int>::iterator foundCity = cityPopulations.find(searchCityName);
    if (foundCity != cityPopulations.end())
    {
        cout << foundCity->first << " " << foundCity->second << endl;
    }
    else
    {
        cout << "No information about " << searchCityName << endl;
    }

    return 0;
}

