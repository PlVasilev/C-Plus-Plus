#ifndef FILTER_FACTORY_H
#define FILTER_FACTORY_H

#include <string>

using namespace std;

class UpperFilter : public Filter
{
public:
	bool shouldFilterOut(char symbol) const override
	{
		return  std::isupper(symbol);
	}
};

class LowerFilter : public Filter
{
	bool shouldFilterOut(char symbol) const override
	{
		return  std::islower(symbol);
	}
};

class NumbersFilter : public Filter
{
	bool shouldFilterOut(char symbol) const override
	{
		return  std::isdigit(symbol);
	}
};

class FilterFactory
{
public:
	FilterFactory() = default;

	Filter* buildFilter(string& filterDefinition) const
	{
		if (filterDefinition == "A-Z")
		{
			return new UpperFilter();
		}
		if (filterDefinition == "a-z")
		{
			return new LowerFilter();
		}
		if (filterDefinition == "0-9")
		{
			return new NumbersFilter();
		}
	}
};



#endif // !FILTER_FACTORY_H