#ifndef MAKE_COMPANY_H 
#define MAKE_COMPANY_H

#include "Company.h"
#include <memory>

std::shared_ptr<Company> makeCompany(std::vector<std::string>& properties)
{
	std::vector<std::pair<char, char> > employees;
	for (int i = 2; i < properties.size(); ++i)
	{
		std::pair<char, char> pair;
		pair.first = properties[i][0];
		pair.second = properties[i][1];
		employees.emplace_back(pair);
	}
	return  std::make_shared<Company>(Company(std::stoi(properties[0]), properties[1], employees));
}



#endif // !MAKE_COMPANY_H #pragma once
