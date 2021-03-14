#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Company.h"

using namespace std;

std::vector<std::string> readStringsLine() {
	std::vector<std::string> values;

	std::string line;
	std::getline(std::cin, line);

	std::istringstream lineIn(line);

	std::string value;
	while (lineIn >> value) {
		values.push_back(value);
	}

	return values;
}

int main()
{
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	vector<Company> companies;
	
	std::vector<std::string> properties = readStringsLine();
	while (properties[0] != "end") {
		Company company = (Company(std::stoi(properties[1]), properties[0]));
		companies.push_back(company);
		properties = readStringsLine();
	}
	
	properties = readStringsLine();
	
	if (properties[0] == "id")
	{
		sort(companies.begin(), companies.end(), []( Company lhs,  Company rhs) {
			return lhs.getId() < rhs.getId();
			});
		for (auto company : companies)
		{
			cout << company.toString() << endl;
		}		
	}

	if (properties[0] == "name")
	{
		sort(companies.begin(), companies.end(), [](Company lhs, Company rhs) {
			return lhs.getName() < rhs.getName();
			});
		for (auto company : companies)
		{
			cout << company.toString() << endl;
		}
	}

	
	return 0;
}


