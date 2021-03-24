#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <list>
#include <math.h> 
#include <stack>
using namespace std;

int main()
{
    int num;
    cin >> num;
    cin.ignore();
    vector<int> glass;
    vector<int> metal;
    vector<int> plastic;
    int index = 0;
    for (int i = 0; i < num; ++i)
    {     
        string input;
        string input2;
        cin >> input >> input2;

        if (input == "glass")
        {
            index++;
            if (input2 == "front")
            {
                if (glass.empty()) glass.push_back(index);
                else  glass.insert(glass.begin(), index); 
            }
            else
            {
                glass.push_back(index);
            }
        }
        else if(input == "metal")
        {
            index++;
            if (input2 == "front")
            {
	            if (metal.empty())
	            {
                    metal.push_back(index);
	            }
	            else
	            {
                    metal.insert(metal.begin(), index);
	            }
               
            }
            else
            {
                metal.push_back(index);
            }
        }
        else if (input == "plastic")
        {
            index++;
            if (input2 == "front")
            {
                if (plastic.empty()) plastic.push_back(index);
                else  plastic.insert(plastic.begin(), index);
            }
            else
            {
                plastic.push_back(index);
            }
        }

    }
    if (!glass.empty())
    {
	    std::cout << "glass -" ;
        for (auto value : glass)
        {
            cout << " " << value;
        }
        cout << endl;
    }

    if (!metal.empty())
    {
        std::cout << "metal -";
        for (auto value : metal)
        {
            cout << " " << value;
        }
        cout << endl;
    }

    if (!plastic.empty())
    {
        std::cout << "plastic -";
        for (auto value : plastic)
        {
            cout << " " << value;
        }
        cout << endl;
    }
 
}


