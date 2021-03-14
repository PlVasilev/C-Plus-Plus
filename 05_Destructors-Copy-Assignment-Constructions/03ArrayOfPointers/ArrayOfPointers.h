#ifndef ARRAY_OF_POINTERS_H
#define ARRAY_OF_POINTERS_H

class ArrayOfPointers
{
	std::vector<Company*> companiesArray;
public:
	ArrayOfPointers() : companiesArray(std::vector<Company*>{}) {}

	
	void add(Company* c)
	{	
		this->companiesArray.push_back(c);		
	}

	size_t getSize() const
	{
		return this->companiesArray.size();
	}

	Company* get(int index) const
	{
		return this->companiesArray.at(index);
	}

	~ArrayOfPointers()
	{
		for (std::vector<Company*>::value_type company : companiesArray)
		{
			delete company;
		}
	}
};

#endif // !ARRAY_OF_POINTERS_H