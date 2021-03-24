#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>
#include "cmath"
#include <chrono>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <map>


using namespace std;

int main()
{
	vector<int> numbers1;

	vector<int> numbers2;

	//string input;
	//getline(cin, input);

	char source[] = "One";
	char destination[100] = "Two";

	//CONCAT
	strcat_s(destination, source);

	cout << destination << endl;

	//GET Length
	cout << strlen(destination) << endl;

	//Search in string from mach to the end
	char* foundStr = strstr(destination, source);
	cout << foundStr << endl;

	//Search in string FOUND INDEX
	int index = foundStr - destination;
	cout << index << endl;

	string theFoxPart = "the quick brown fox";
	string theActionPart("jumps over");
	char dogPartCString[] = "the lazy dog";
	string sentence = theFoxPart + string("---") + theActionPart + string(3, '-') + dogPartCString;

	cout << theFoxPart.size();

	string hello = "Hello";
	hello[1] = 'a';
	cout << hello << endl; //”hallo”

	// operators <, <=, ==, >=, > compare the strings lexicographically
	string s1 = "cat", s2 = "canary";
	if (s1 < s2)
		cout << s1 << " is before " << s2 << endl;
	else
		cout << s1 << " is after " << s2 << endl;

	// str.find(search) returns the index of search in the str
	// 	If search is not found, returns the string::npos value(-1)
	string s = "SoftUni";
	cout << "Uni" << " at the index" << s.find("Uni") << " in " << s;

	// std::string Find All Occurrences
	string str = "canary";
	int foundIndex = str.find("a");
	while (foundIndex != string::npos) {
		cout << foundIndex << endl;
		foundIndex = str.find("a", foundIndex + 1);
	}

	// std::string Substring, Erase, Replace
	//	substr(index, length) returns a new string
	//	With length characters, starting from index
	string s12 = "abc";
	cout << s12.substr(1, 2);//"bc"

	//erase(index, length) changes a string by removing chars
	//	Removes length characters, starting from index
	string s14 = "abc";
	cout << s14.erase(1, 2); // "a"


	//	replace(index, length, str) changes a string by replacing
	//	Characters in[index, index + length) replaced by str
	string s11 = "abc"; s.replace(1, 2, "cme");
	cout << s11 << endl; // "acme"

	// STREAMS
	//The std::stringstream (1)
	//	A stream that works on a string (instead of the console or a file)
	//	#include<sstream>
	//	Can read data from a string, can write data to a string
	//	There are limited istringstream / ostringstream versions that only read / write respectively
	string strStr = "3 -2";
	istringstream numbersStream(strStr); // ONLY READ

	int num1, num2;
	numbersStream >> num1 >> num2;
	int sum = num1 + num2;

	//Writing with std::ostringstream
	ostringstream stream;
	stream << "The sum is " << num1 + num2 << endl;
	cout << stream.str();

	// Reading with getline() and Streams
	// getline(stream, targetStr) reads an entire line of text
	// 	Or until a delimiter char(additional parameter) is reached
	// 	From the provided streamand puts it into targetStr
	// 	Avoid mixing cin >> and getline(cin, …)
	istringstream in("a word");
	string line;
	getline(in, line);
	cout << line << endl; // a word

	istringstream in2("a.word");
	string line2;
	getline(in2, line2, '.');
	cout << line << endl; // a

	//	Parsing Numbers from a Line
	//getline() already gives us the line as a string
	//	Streams allow us to read strings / numbers separated by spaces
	//	How do we know when to stop ?
	//	Streams can be used as a bool value
	//	A stream is true if it still has something to read
	//	A stream is false if the input ended, or if there was an error
	//	Read the line from cin into a string with getline()
	//	Create an istringstream over that string
	//	Read numbers from the stream while the stream is true
	string line3; getline(cin, line3);
	istringstream lineStream(line3);
	vector<int> numbers;
	int currentNumber;
	while (lineStream >> currentNumber) {
		numbers.push_back(currentNumber);
	}

	//		Streams to and from Files (1)
	//  We saw that streams work the same way
	//	Regardless of whether they are over the console, or a string
	//	Same goes for files – you just have to create a file stream
	//  ifstream is for reading, ofstream is for writing
	//	Text reading / writing with same operators, functions, concepts
	//	<< for writing, >> for reading, getline() reads line, etc.
	//	Can be used as bool just like cin, coutand stringstream

	// Using Streams to/from Files
	ifstream input;
	input.open("input.txt");
	int a, b;
	input >> a >> b;
	input.close();

	ofstream output;
	output.open("output.txt");
	output << a + b << endl; output.close();

	//  close() is automatically called when stream goes out of scope
	//	i.e.when the declaring block ends
	//	Still, you should close explicitly if you're not using the stream
	//	To make an output stream append instead of overwrite :
	//	std::ofstream output("output.txt", fstream::app);

}

