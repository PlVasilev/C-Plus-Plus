#include <iostream>
#include <string>
#include <vector>

using namespace std;

void readRust(std::vector<std::string>& outInput)
{
	int rows = 10;
	int cols = 10;

	outInput.resize(rows);
	for (int i = 0; i < rows; ++i)
	{
		outInput[i].resize(cols);
	}

	for (int row = 0; row < rows; ++row)
	{
		std::cin >> outInput[row];
	}
}

extern void printMatrix(const std::vector<std::string>& matrix);

void expandSingleRust(std::vector<std::string>& rustField,
	const int ROW,
	const int COL)
{
	if (COL < 0 || ROW < 0 || COL >= (int)rustField[0].size() ||
		ROW >= (int)rustField.size())
	{
		return;
	}

	if (rustField[ROW][COL] != '#')
		rustField[ROW][COL] = '!';
}

void expandRust(std::vector<std::string>& rustedMetal, std::vector<int> & rustX, std::vector<int> & rustY)
{
	for (size_t i = 0; i < rustX.size(); ++i)
	{
		int ROW = rustX[i], COL = rustY[i];

		expandSingleRust(rustedMetal, ROW - 1, COL);
		expandSingleRust(rustedMetal, ROW, COL - 1);
		expandSingleRust(rustedMetal, ROW, COL + 1);
		expandSingleRust(rustedMetal, ROW + 1, COL);
	}
}

extern void findMines(const std::vector<std::string>& matrix,
	std::vector<int>& minesX,
	std::vector<int>& minesY);


int main()
{
	//1) read input
	std::vector<std::string> rustedMetal;
	readRust(rustedMetal);

	int ticks; 
	cin >> ticks; // how many time ticks we need to calculate

	//3) expand rust 'ticks' times
	while (ticks--) {
		//cout << "TICK: " << ticks + 1 << endl;
		//cout << "====================";

		std::vector<int> rustX;
		std::vector<int> rustY;
		findMines(rustedMetal, rustX, rustY); // analyze and locate rust's coordinates

		// DEBUG INFO
		//for (int i = 0; i < rustX.size(); i++)
		//	cout << "(" << rustX[i] << ", " << rustY[i] << "),   ";

		expandRust(rustedMetal, rustX, rustY); // extend new rust on the rustedMetal
		//printMatrix(rustedMetal);
	}

	//4) print answer
	printMatrix(rustedMetal);

	return 0;
}

/*
=== 0 ===
..........
....!.....
..........
..........
..........
..........
..........
..........
..........
..........

=== 1 ===
....!.....
...!!!....
....!.....
..........
..........
..........
..........
..........
..........
..........



*/