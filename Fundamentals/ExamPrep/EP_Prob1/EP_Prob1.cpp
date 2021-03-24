#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <list>
#include <math.h> 
#include <stack>
using namespace std;

int main()
{
	string input;
	getline(cin, input);

	map<int, int> brackets;
	int value = 0;
	//!"#$%&'()*+,-./:;<=>?@[]^_`{}~
	for (char i : input)
	{
		switch (i)
		{
		case'|':
		{
			brackets[value] += 1;
			value = 0;
		}; break;
		case'!':value++; break;
		case'"':value++; break;
		case'#':value++; break;
		case'$':value++; break;
		case'%':value++; break;
		case'&':value++; break;
		case'\'':value++; break;
		case'(':value++; break;
		case')':value++; break;
		case'*':value++; break;
		case',':value++; break;
		case'-':value++; break;
		case'.':value++; break;
		case'/':value++; break;
		case':':value++; break;
		case';':value++; break;
		case'<':value++; break;
		case'=':value++; break;
		case'>':value++; break;
		case'?':value++; break;
		case'@':value++; break;
		case'[':value++; break;
		case']':value++; break;
		case'^':value++; break;
		case'_':value++; break;
		case'`':value++; break;
		case'{':value++; break;
		case'}':value++; break;
		case'~':value++; break;
		default: ;
		}
	}
	for (auto bracket : brackets)
	{
		cout << bracket.first << " symbol sentences: " << bracket.second << endl;
	}
}


