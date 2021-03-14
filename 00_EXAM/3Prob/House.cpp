#include "House.h"

House::House(int width, int length):Building(width, length)
{
	//std::cout << this << std::endl;
	std::cout << "Building type: House, measurements: " << width << " x " << length << std::endl;
	std::cout << "| Constructor is called" << std::endl;
}

House::~House()
{
	//std::cout << this << std::endl;
	std::cout << "Building type: House, measurements: " << this->getWidth() << " x " << this->getLength() << std::endl;
	std::cout << "| Destructor is called" << std::endl;
}


void House::print()
{
	
}
