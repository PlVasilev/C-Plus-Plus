#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main_sort_array()
{
    vector<int> numsVector{ 61, 41, 231, 764, 45 };
    sort(numsVector.begin(), numsVector.end(), std::less<int>());
    for (int num : numsVector)
    {
        cout << num << " ";
    }
    cout << endl << endl;

    string wordsArray[6]{ "whales", "cats", "dogs", "fish", "cheetahs", "dodos" };
    sort(wordsArray, wordsArray + 6);
    for (string word : wordsArray)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}

