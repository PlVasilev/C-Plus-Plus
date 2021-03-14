#ifndef SORT_BY_H 
#define SORT_BY_H 

#include "Company.h" 
#include <algorithm>

bool(*globalComparator)(const Company& a, const Company& b) = nullptr;

bool internalSort(Company* company, Company* endCompany)
{
	return globalComparator(*company , *endCompany);
}

void sortBy(Company** company, Company** endCompany, bool(*sortBy)(const Company& a, const Company& b) )
{
	globalComparator = sortBy;
	std::sort(company, endCompany, internalSort);
}


#endif // !SORT_BY_H 
