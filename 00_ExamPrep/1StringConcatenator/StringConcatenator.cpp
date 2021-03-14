
#include <string>
#include "StringConcatenator.h"

StringConcatenator::StringConcatenator()
{
	
}


StringConcatenator::~StringConcatenator()
{

}

std::string StringConcatenator::concatenate(const ConcatenateStrategy strategy,
	const char* left,
	const size_t leftSize,
	const char* right,
	const size_t rightSize) const
{
	std::string result;
	
	if (strategy == ConcatenateStrategy::LEFT_1_RIGHT_1)
	{
		for (size_t i = 0; i < leftSize; ++i)
		{
			result += left[i];
			if (i >= rightSize)
			{
				continue;
			}
			result += right[i];
		}
	}
	
	if (strategy == ConcatenateStrategy::LEFT_2_RIGHT_1)
	{
		for (size_t i = 0; i < leftSize; i+=2)
		{
			result += left[i];
			if (i + 1 < leftSize)
			{
				result += left[i + 1];
			}
			
			if (i/2 >= rightSize)
			{
				continue;
			}
			result += right[i/2];
			if (i == leftSize - 1 || i == leftSize - 2)
			{
				for (size_t j = i/2 + 1; j < rightSize; ++j)
				{
					result += right[j];
				}
			}
		}
	}

	if (strategy == ConcatenateStrategy::LEFT_1_RIGHT_2)
	{
		for (size_t i = 0; i < leftSize; ++i)
		{
			result += left[i];

			if (i * 2 >= rightSize)
			{
				continue;
			}
		
			result += right[i*2];
			if (i*2 + 1 < rightSize)
			{
				result += right[i*2 + 1];
			}
			
			if (i == leftSize - 1)
			{
				for (size_t j = i * 2 + 1; j < rightSize; ++j)
				{
					result += right[j];
				}
			}
		}
	}
	if (leftSize == 0)
	{
		for (int i = 0; i < rightSize; ++i)
		{
			result += right[i];
		}
	}

	return result;
}