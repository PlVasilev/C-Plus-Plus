#ifndef PARSE_COMPANIES_H 
#define PARSE_COMPANIES_H 


#include "Company.h"
#include <vector>
#include <new>

using namespace std;

Company* parseUniqueCompanies(std::string input, int& num, string (*function)(const Company&))
{
    int sizeOfStr = input.size();
    int currentNum = 0;
    std::string currentName;
    std::vector<Company> vecComp;
    int size = 0;
    num = 0;

    for (int i = 0; i < sizeOfStr; i++) {
        if (isdigit(input[i]))
            currentNum = (currentNum * 10) + (input[i] - '0');

        if (input[i] == ' ')
        {
	        continue;
        }
    	
        if (!isdigit(input[i]) && input[i] != '\n') {
            currentName += input[i];
            size++;
        }

        if (input[i] == '\n') {
            bool isThere = false;
            for (std::vector<Company>::iterator it = vecComp.begin(); it != vecComp.end(); it++) {
                if (function(*it) == function(Company(currentNum, currentName))) {
                    isThere = true;
                }
            }
            if (isThere == false) {
                vecComp.push_back(Company(currentNum, currentName));
                num++;
            }
            currentName = "";
            currentNum = 0;
        }
    }

    Company* array = new Company[size];
    int a = 0;
    for (std::vector<Company>::iterator b = vecComp.begin(); b != vecComp.end(); b++) {
        Company* ptr = new Company(b->getId(), b->getName());
        array[a] = *ptr;
        delete ptr;
        a++;
    }

    return array;
}



#endif // !PARSE_COMPANIES_H 
