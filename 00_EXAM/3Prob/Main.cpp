#include <vector>
#include "Tropico.h"
#include "Building.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;



int main()
{

	int lineCount = 0;
	std::string input;
	std::istringstream istr;



	Tropico tropico; // change name 

	std::cin >> lineCount;
	std::cin.ignore();

	for (int i = 0; i < lineCount; ++i) {

		getline(std::cin, input);
		istr.clear();
		istr.str(input);
		string command;
		istr >> command;
		
		if (command == "build")
		{
			string typeBuilding;
			int width = 0 ;
			int length = 0;
			istr >> typeBuilding >> width >> length;
			if (typeBuilding == "Palace")
			{
				tropico.build(typeBuilding, width, length);
			}
			if (typeBuilding == "House")
			{
				tropico.build(typeBuilding, width, length);
			}	
		}else if (command == "replace")
		{
			int firstPos;
			int secondPos;
			istr >> firstPos >> secondPos;
			tropico.replace(firstPos, secondPos);
		}
		else if (command == "duplicate")
		{
			int firstPos;
			int secondPos;
			istr >> firstPos >> secondPos;
			tropico.duplicate(firstPos, secondPos);
			
		}
		else if (command == "demolish")
		{
			int firstPos;
			istr >> firstPos;
			tropico.demolish(firstPos);
			
		}
		
		//istr >> characteristics.name >> characteristics.power >> characteristics.magicItem;
		//statistics << characteristics;
	}
	//statistics.printAll();
}