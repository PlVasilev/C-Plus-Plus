#ifndef REMOVE_DUPLICATES_H 
#define REMOVE_DUPLICATES_H 

#include "Company.h"
#include <list>
#include <set>


void removeDuplicates(std::list<Company*>& companies)
{
	// std::set<Company*> found;
	std::set<std::string> found;
	for (std::list<Company*>::iterator x = companies.begin(); x != companies.end();) {
		std::string currentCompanyName = (*x)->getName();
		if (found.find(currentCompanyName) == found.end())
		{
			found.insert(currentCompanyName);
			++x;
		}
		else {
			x = companies.erase(x);
		}

		//if (!found.insert(*x).second) {
		//    x = companies.erase(x);
		//}
		//else {
		//    ++x;
		//}
	}
}




#endif // !REMOVE_DUPLICATES_H 
