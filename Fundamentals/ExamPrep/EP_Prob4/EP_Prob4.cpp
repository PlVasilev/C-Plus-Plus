// EP_Prob4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int bombPower = 0;

	vector<vector<int>> numbersArr;
	int rows, cols;
	cin >> rows >> cols;
	for (int i = 0; i < rows; ++i)
	{
		vector<int> numbers;
		if (i == 0)std::cin.ignore();
		string line3; 
		getline(std::cin, line3);
		for (int j = 0; j < cols; ++j)
		{
			numbers.push_back(line3[j] - 48);
		}
		numbersArr.push_back(numbers);
	}
	int commandsNumber;
	cin >> commandsNumber;

	for (int i = 0; i < commandsNumber; ++i)
	{
		if (i == 0)std::cin.ignore();
		string line3; getline(cin, line3);
		istringstream lineStream(line3);
		vector<string> command;
		string word;
		while (lineStream >> word) command.push_back(word);
		if (command[0] == "power")
		{
			if (command[1] == "up")
			{
				bombPower++;
				cout << "Increased bomb power to " << bombPower << endl;
			}
			else
			{
				if (bombPower > 0) bombPower--;
				cout << "Decreased bomb power to " << bombPower << endl;
			}
		}
		else if (command[0] == "bomb")
		{			
			int x = stoi(command[1]);
			int y = stoi(command[2]);
			

			int points = 0;
			points += numbersArr[x][y];
			numbersArr[x][y] = 0;
			for (int i = 1; i <= bombPower; ++i)
			{
				if (x + i < rows)
				{
					points += numbersArr[x + i][y];
					numbersArr[x + i][y] = 0;
				} 
				if (x - i >= 0) {
					points += numbersArr[x - i][y];
					numbersArr[x - i][y] = 0;
				}
				if (y + i < cols)
				{
					points += numbersArr[x][y + i];
					numbersArr[x][y + i] = 0;
				} 
				if (y - i >= 0)
				{
					points += numbersArr[x][y - i];
					numbersArr[x][y - i] = 0;
				} 
			}
			cout << points << " points" << endl;
		}
	}
}


