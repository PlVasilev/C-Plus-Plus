#include "MemoryMonitor.h"
#include "Structs.h"

#include <iostream>


MemoryMonitor::MemoryMonitor()
{
	
}

MemoryMonitor::~MemoryMonitor()
{
	this->_nodes.clear();
}

MemoryNode MemoryMonitor::getLastNode() const
{
	return this->_nodes.back();
}

void MemoryMonitor::pushNode(const int nodeSize)
{
	// IntArray(int size) : data(new int[size]), size(size) {}
	
	MemoryNode* node;
	node = new MemoryNode();
	node->size = nodeSize;
	auto data = new int[nodeSize];
	node->data = data;
	this->_nodes.push_back(*node);
	std::cout << "Pushed node with memory occupation: " << nodeSize * 4 << std::endl;
};

void MemoryMonitor::popNode()
{
	if (this->_nodes.size() == 0)
	{
		std::cout << "No nodes to pop"  << std::endl;
		return;
	}

	auto node = this->_nodes.back();
	
	std::cout << "Popped node with memory occupation: " << node.size * 4 << std::endl;

	delete[] this->_nodes.back().data;
	this->_nodes.pop_back();
};

void MemoryMonitor::printMemoryOccupation(const int numberOfNodes)
{
	int a = numberOfNodes;
	if (this->_nodes.size() < numberOfNodes)
	{
		a = this->_nodes.size();
	}
	int result = 0;
	for (int i = 0; i < a; ++i)
	{
		result += this->_nodes[i].size;
	}

	std::cout << "Memory occupation for first " << numberOfNodes << " memory nodes is: " << result * 4 << std::endl;
};