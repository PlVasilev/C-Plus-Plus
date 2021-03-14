#include "Register.h"

Register::Register(size_t numCompanies) : numAdded(0), companiesArray(new Company[numCompanies]){}
	

void Register::add(const Company& c)
{
	this->companiesArray[numAdded] = c;
	numAdded++;
}

Company Register::get(int companyId) const
{
	for (int i = 0; i < this->numAdded; ++i)
	{
		if (this->companiesArray[i].getId() == companyId)
		{
			return companiesArray[i];
		}
	}

	return Company();
}

Register::~Register()
{
	delete[] this->companiesArray;
}
