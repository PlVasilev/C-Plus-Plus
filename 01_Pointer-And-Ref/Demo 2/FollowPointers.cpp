
#include "Node.h"
#include "FollowPointers.h"

int getSumFrom(Node* start) {
	
	int sum = 0;
	while (start != nullptr)
	{
		sum += start->value;
		start = start->next;
	}
	
	return sum;
}

int getSumFrom_recursive(Node* start) 
{
	if (start == nullptr)
		return 0;

	return start->value + getSumFrom_recursive(start->next);
}
