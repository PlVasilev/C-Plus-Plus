#include "Palace.h"

Palace::Palace(int width, int length):Building(width,length)
{
	//std::cout << this << std::endl;
	std::cout << "Building type: Palace, measurements: " << width << " x " << length << std::endl;
	std::cout << "| Constructor is called" << std::endl;
};

Palace::~Palace()
{
	//std::cout << this << std::endl;
	std::cout << "Building type: Palace, measurements: " << this->getWidth() << " x " << this->getLength() << std::endl;
	std::cout << "| Destructor is called" << std::endl;
}

void Palace::print()
{
	
}