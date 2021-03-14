#include <iostream>
#include <stack>

#include "ContainerInterface.h"
#include "Defines.h"
#include "MemoryContainer.h"

using namespace std;

void pushContainer(const ContainerType                containerType,
    const size_t		                  containerSize,
    std::stack<ContainerInterface*>& containers,
    size_t& occupiedMemory)
{
	if (containerType == ContainerType::SHORT_CONTAINER)
	{
		containers.push(new MemoryContainer<short>(containerSize));
		occupiedMemory += containerSize * 2;
	}
	if (containerType == ContainerType::INT_CONTAINER)
	{
		containers.push(new MemoryContainer<int>(containerSize));
		occupiedMemory += containerSize * 4;
	}
	if (containerType == ContainerType::LONG_LONG_CONTAINER)
	{
		containers.push(new MemoryContainer<long long>(containerSize));
		occupiedMemory += containerSize * 8;
	}
	cout << "occupiedMemory: " << occupiedMemory << endl;
};

void popContainer(std::stack<ContainerInterface*>& containers,
    size_t& occupiedMemory)
{
	if (containers.size() == 0)
	{
		cout << "occupiedMemory: " << occupiedMemory << endl;
	}
	else
	{
		auto container = containers.top();
		auto memory = container->getOccupiedMemory();
		occupiedMemory -= container->getOccupiedMemory();
		cout << "occupiedMemory: " << occupiedMemory << endl;
		delete container;
		containers.pop();
	}
};

