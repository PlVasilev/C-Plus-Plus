#ifndef ORDEREDINSERTER_H
#define ORDEREDINSERTER_H

#include <algorithm>

#include "Company.h"

class OrderedInserter
{
	std::vector<const Company*> &companies;
public:
	OrderedInserter(std::vector<const Company*> &companies) :
		companies(companies)
	{ };

	int insert(const Company* c)
	{
		companies.push_back(c);
		// std::sort(companies.begin(), companies.end());
		std::sort(companies.begin(), companies.end(), [](const Company* lhs, const Company* rhs) {
			return lhs->getId() < rhs->getId();
			});
		return 0;
	}
};


#endif //!ORDEREDINSERTER_H
