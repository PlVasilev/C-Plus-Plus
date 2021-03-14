#ifndef MAGIK_KINGDOM_H_
#define MAGIK_KINGDOM_H_

#include <algorithm>
#include <vector>

#include "Struct.h"

using namespace std;

struct Asending {
	bool operator() (Villager i, Villager j) { return (i.power < j.power); }
} asending;


struct Desending {
	bool operator() (Villager i, Villager j) { return (i.power > j.power); }
} desending;

class MagicKingdom
{
public:
	vector<Villager> magician;
	vector<Villager> commoner;
	vector<Villager> antiMagic;

	void printAll()
	{
		std::sort(antiMagic.begin(), antiMagic.end(), asending);
		std::sort(commoner.begin(), commoner.end(), desending);
		std::sort(magician.begin(), magician.end(), desending);

		cout << "Anti-Mages:" << endl;
		for (int i = 0; i < this->antiMagic.size(); ++i)
		{
			cout << antiMagic[i].name << " - " << antiMagic[i].magicItem  << endl;
		}
		cout << "Commoners:" << endl;
		for (int i = 0; i < this->commoner.size(); ++i)
		{
			cout << commoner[i].name << " - " << commoner[i].magicItem  << endl;
		}
		cout << "Mages:" << endl;
		for (int i = 0; i < this->magician.size(); ++i)
		{
			cout << magician[i].name << " - " << magician[i].magicItem << endl;
		}
	}
	
	friend MagicKingdom& operator<<(MagicKingdom& statistics,  Villager& info);
};

MagicKingdom& operator<<(MagicKingdom& statistics, Villager& info)
{
	if (info.power < 0)
	{
		statistics.antiMagic.push_back(info);
		
	}
	else if (info.power < 100)
	{
		statistics.commoner.push_back(info);
	}else
	{
		statistics.magician.push_back(info);
	}
	return statistics;

}


#endif /* MAGIK_KINGDOM_H_ */