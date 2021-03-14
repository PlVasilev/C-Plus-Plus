#ifndef CITY_UNITS_H
#define CITY_UNITS_H

#include <algorithm>
#include <string>
#include <cstddef>
#include "City.h"
#include <string>

using namespace std;

City* initCity(string& name, size_t& population)
{
	return new City(name, population);
}

struct myclass {
	bool operator() (const City* i, const City* j) { return (i->getPopulation() < j->getPopulation()); }
} myobject;


vector<pair<size_t, const City*>> groupByPopulation(vector<const City*>&  cities, size_t&  totalPop)
{
	totalPop = 0;
	vector<pair<size_t, const City*>> result;
	 std::sort(cities.begin(), cities.end(), myobject);
	for (int i = 0; i < cities.size(); ++i)
	{
		pair<size_t, const City*> obj;
		obj.first = cities[i]->getPopulation();
		obj.second = cities[i];
		totalPop += cities[i]->getPopulation();
		result.push_back(obj);
	}
	 return result;
}



#endif // !CITY_UNITS_H