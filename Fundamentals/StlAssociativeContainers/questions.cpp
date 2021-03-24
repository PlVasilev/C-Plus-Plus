#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>

int main_questions()
{
    using namespace std;

    set<int> digits{ 4, 1, 4, 0, 2, 6, 9, 1, 8, 6, 2, 3, 5, 6, 7 };
    map<int, string> digits2;

    for (int d : digits)
    {
        digits2[d]="";
    }
    cout << endl;

    cout << endl;

    set<char> letters;
    string sentence = "the quick brown fox jumps over the lazy dog";
    istringstream sentenceIn(sentence);
    char letter;
    while (sentenceIn >> letter)
    {
        letters.insert(letter);
    }

    for (set<char>::iterator i = letters.begin(); i != letters.end(); i++)
    {
        cout << *i;
    }
    cout << endl;

    return 0;
}

