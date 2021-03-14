#ifndef STATISTICS_H
#define STATISTICS_H
#include <algorithm>
#include <vector>

using namespace std;

struct Asending {
	bool operator() ( PersonInfo i,  PersonInfo j) { return (i.age < j.age); }
} asending;


struct Desending {
	bool operator() ( PersonInfo i,  PersonInfo j) { return (i.age > j.age); }
} desending;

class Statistics
{
public:
	vector<PersonInfo> minors;
	vector<PersonInfo> adulst;
	vector<PersonInfo> elders;


	Statistics() {  }

	void printStatistics()
	{
		std::sort(elders.begin(), elders.end(), desending);
		std::sort(adulst.begin(), adulst.end(), asending);
		std::sort(minors.begin(), minors.end(), asending);
		cout << "Elders data:" << endl;
		for (int i = 0; i < this->elders.size(); ++i)
		{
			cout << elders[i].firstName << " " << elders[i].lastName << " " << elders[i].height << endl;
		}
		cout << "Adults data:" << endl;
		for (int i = 0; i < this->adulst.size(); ++i)
		{
			cout << adulst[i].firstName << " " << adulst[i].lastName << " " << adulst[i].height << endl;
		}
		cout << "Minors data:" << endl;
		for (int i = 0; i < this->minors.size(); ++i)
		{
			cout << minors[i].firstName << " " << minors[i].lastName << " " << minors[i].height << endl;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const PersonInfo& info);

	friend std::ostream& operator<<(const Statistics& statistics, const PersonInfo& info);
};

std::ostream& operator<<(std::ostream& out, const PersonInfo& resource) {
	return out ;
}

Statistics& operator<<( Statistics& statistics, const PersonInfo& info) {
	if (info.age <= 18)
	{
		statistics.minors.push_back(info);
	}
	else if (info.age <= 62)
	{
		statistics.adulst.push_back(info);
	}else
	{
		statistics.elders.push_back(info);
	}
	return statistics;
	
}
#endif // !STATISTICS_H