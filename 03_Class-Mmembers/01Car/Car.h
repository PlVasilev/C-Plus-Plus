#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
class Car {
private:
	const string sBrand;
	const string sModel;
	const int nYear;
	
public:
	const std::string id;

	Car(std::string sBrand, string sModel, int  nYear) :
		sBrand(sBrand),
		sModel(sModel),
		nYear(nYear)
	{}

	const string& GetBrand() const
	{
		return this->sBrand;
	}

	const string& GetModel() const
	{
		return this->sModel;
	}

	const int& GetYear() const
	{
		return this->nYear;
	}

	
};

#endif //CAR_H