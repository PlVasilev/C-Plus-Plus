#ifndef MIN_BY_H 

#define MIN_BY_H 

using namespace std;

string minBy(vector<string> values, bool (*minmax)(const string&, const string&))
{
	string filtered;

	if (values.size() == 1)
	{
		return values[0];
	}
	
	for (auto i = 0; i < values.size() -1; ++i)
	{
		if (i == 0)
		{
			if (minmax(values[i], values[i + 1]))
			{
				filtered = values[i];
			}
			else
			{
				filtered = values[i + 1];
			}
		}
		else
		{
			if (minmax(values[i + 1], filtered))
			{
				filtered = values[i + 1];
			}
		}
	
	}
	return filtered;
}



#endif // !MIN_BY_H 
