#ifndef PROFITREPORT_H
#define PROFITREPORT_H

#include <algorithm>

#include "Company.h"
#include "ProfitCalculator.h"

std::string getProfitReport(Company* start, Company* end, std::map<int, ProfitCalculator> profitCalculatorsByCompany)
{
	std::string result = "";

	for (auto* it = start; it != end + 1; ++it)
	{
		for (auto profit : profitCalculatorsByCompany)
		{
			if (it->getId() == profit.first)
			{
				result += it->getName() + " = " + std::to_string(profit.second.calculateProfit(*it)) + "\n";
			}
		}
	}
	
	return result;
}


#endif
