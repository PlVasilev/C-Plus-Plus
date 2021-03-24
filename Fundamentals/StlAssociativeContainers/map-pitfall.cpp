#include <iostream>
#include <map>


int main_map_pitfall()
{
    using namespace std;

    map<string, int> cityPopulations =
    {
        {"Gabrovo", 58950},
        {"Sofia", 1307376},
        {"Melnik", 385}
    };

    map<int, string> numberNames{ {2, "abc" } };

    for (unsigned long i = 0; i < numberNames.size(); i++)
    {
        cout << numberNames[i] << ",";
    }

    return 0;
}

