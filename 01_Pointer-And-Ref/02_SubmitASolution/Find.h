#ifndef FIND_H
#define FIND_H

#include "Company.h"

extern Company* find(std::vector<Company*> companies, int id)
{
	for (auto company : companies)
	{
		if (company->getId() == id)
			return company;
		
	}
	return nullptr;
}

#endif //!FIND_H