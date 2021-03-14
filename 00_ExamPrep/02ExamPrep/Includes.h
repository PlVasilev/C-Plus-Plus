#ifndef INCLUDES_H
#define INCLUDES_H

#include <iostream>
#include <vector>
#include "City.h"

std::istream& operator>>(std::istream& in, City& city) {
  unsigned int censusYear;
  std::string name;
  size_t population;

  in >> name >> population >> censusYear;

  city = City(censusYear, name, population);

  return in;
}



class CityDiff
{
	int diff;
	City first;
	City second;
	
public:
	CityDiff(int diff, const City& s1, const City& s2): diff(diff),first(s1),second(s2) {  }

	City getFirst() const
	{
		return this->first;
	}

	City getSecond() const
	{
		return this->second;
	}

	int getDiff() const
	{
		return this->diff;
	}
	
	friend std::istream& operator>>(std::istream& in, City& resource);

	friend std::ostream& operator<<(std::ostream& out, const CityDiff& resource);
};

CityDiff operator-(const City& s1, const City& s2) {
	CityDiff diff(s1.getPopulation() - s2.getPopulation(),s1,s2);
	return diff;
}

std::ostream& operator<<(std::ostream& out, const CityDiff& diff) {
	if (diff.getFirst().getName() == diff.getSecond().getName())
	{
		out << diff.getFirst().getName() << " (" << diff.getFirst().getCensusYear() << " vs. " << diff.getSecond().getCensusYear() << ")" << std::endl;	
	}
	else
	{
		out << diff.getFirst().getName() << " (" << diff.getFirst().getCensusYear()  << ")" << " vs. " << diff.getSecond().getName() << " (" << diff.getSecond().getCensusYear() << ")" << std::endl;
	}
	if (diff.getDiff() >= 0 )
	{
		out << "population: +" << diff.getDiff() << std::endl;
		
	}
	else
	{
		out << "population: " << diff.getDiff() << std::endl;
	}
	return out;
}

#endif // !INCLUDES_H