#ifndef SCIENTIFIC_FIELD_H_
#define SCIENTIFIC_FIELD_H_
#include <algorithm>
#include <vector>

using namespace std;

struct Asending {
	bool operator() (Discovery i, Discovery j) { return (i.year < j.year); }
} asending;

class ScientificField
{
public:
	vector<Discovery> Philosophy;
	vector<Discovery> Linguistics;
	vector<Discovery> Physics;
	vector<Discovery> Chemistry;

	void print()
	{
		std::sort(Philosophy.begin(), Philosophy.end(), asending);
		std::sort(Linguistics.begin(), Linguistics.end(), asending);
		std::sort(Physics.begin(), Physics.end(), asending);
		std::sort(Chemistry.begin(), Chemistry.end(), asending);


		cout << "Physics:" << endl;
		for (int i = 0; i < this->Physics.size(); ++i)
		{
			cout << Physics[i].name << " " << Physics[i].year << " - " << Physics[i].scientistName << endl;
		}
		cout << "Linguistics:" << endl;
		for (int i = 0; i < this->Linguistics.size(); ++i)
		{
			cout << Linguistics[i].name << " " << Linguistics[i].year << " - " << Linguistics[i].scientistName << endl;
		}
		cout << "Philosophy:" << endl;
		for (int i = 0; i < this->Philosophy.size(); ++i)
		{
			cout << Philosophy[i].name << " " << Philosophy[i].year << " - " << Philosophy[i].scientistName << endl;
		}
		cout << "Chemistry:" << endl;
		for (int i = 0; i < this->Chemistry.size(); ++i)
		{
			cout << Chemistry[i].name << " " << Chemistry[i].year << " - " << Chemistry[i].scientistName << endl;
		}
	
	
	
	
	}
	
	friend ScientificField& operator<<(ScientificField& field, Discovery& info);
};

ScientificField& operator<<(ScientificField& field, Discovery& info)
{
	if (info.fieldType == 1)
	{
		field.Philosophy.push_back(info);
	}
	if (info.fieldType == 2)
	{
		field.Linguistics.push_back(info);
	}
	if (info.fieldType == 3)
	{
		field.Physics.push_back(info);
	}
	if (info.fieldType == 4)
	{
		field.Chemistry.push_back(info);
	}
	return field;
}


#endif /* SCIENTIFIC_FIELD_H_ */