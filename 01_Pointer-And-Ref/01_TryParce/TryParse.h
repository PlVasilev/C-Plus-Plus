#include <string>
#ifndef TRYPARSE_H

extern bool tryParse(std::string a, int &b)
{
	try
	{
		b = stoi(a);
		return true;
	}
	catch (...)
	{
		return false;
	}
};

#define TRYPARSE_H
#endif //!TRYPARSE_H
