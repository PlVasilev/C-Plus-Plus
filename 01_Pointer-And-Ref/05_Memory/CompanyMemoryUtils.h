#ifndef COMPANYMEMORYUNILS_H
#define COMPANYMEMORYUNILS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

typedef unsigned char byte;

std::vector<Company>  readCompaniesFromMemory(byte* memory, int numCompanies)
{
	std::vector<Company> allCompanies;
    for (int i = 0; i < numCompanies; ++i)
    {
        unsigned char idd = (*memory);
        int id = (int)idd;
        std::vector<char> namee;
        while (memory++)
        {
            if ((*memory) != '\0' || (*memory) != 0)
                namee.push_back((*memory));
            else
                break;
        }
        std::string name;
        for (int k = 0; k < namee.size(); ++k)
        {
            name += namee[k];
        }
        ++memory;
        int numOfEmployees = (int)(*memory);
        std::vector<std::pair <char, char>> employeeNames;
        for (int k = 0; k < numOfEmployees; ++k)
        {
            ++memory;
            char first = toupper((*memory));
            ++memory;
            char second = toupper((*memory));
            employeeNames.push_back(std::pair <char, char> {first, second});
        }
        Company comp(id, name, employeeNames);
        allCompanies.push_back(comp);
        ++memory;
    }
    return allCompanies;
}

#endif // !COMPANYMEMORYUNILS_H#pragma once
