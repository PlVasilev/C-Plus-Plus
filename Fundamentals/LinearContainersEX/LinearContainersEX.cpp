
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{

	// 1
	vector<vector<int>> numbersArr;
	vector<vector<int>> numbersArr2;

	int currentNumber;
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		if (i == 0)cin.ignore();
		string line3; getline(cin, line3);
		istringstream lineStream(line3);
		vector<int> numbers;
		while (lineStream >> currentNumber) numbers.push_back(currentNumber);
		numbersArr.push_back(numbers);
	}
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		if (i == 0)cin.ignore();
		string line4; getline(cin, line4);
		istringstream lineStream2(line4);
		vector<int> numbers2;
		while (lineStream2 >> currentNumber) numbers2.push_back(currentNumber);
		numbersArr2.push_back(numbers2);
	}

	numbersArr == numbersArr2 ? cout << "equal" : cout << "not equal";


	// 2
	 //int rows, columns;
	 //cin >> rows >> columns;
	 //
	 //int matrix[10][10];
	 //
	 //for (int i = 0; i < rows; ++i)
	 //{
	 //	for (int j = 0; j < columns; ++j)
	 //	{
	 //		int current;
	 //		cin >> current;
	 //		matrix[i][j] = current;
	 //	}
	 //}
	 //
	 //int lookingFor;
	 //cin >> lookingFor;
	 //int counter = 0;
	 //
	 //for (int i = 0; i < rows; ++i)
	 //{
	 //	for (int j = 0; j < columns; ++j)
	 //	{
	 //		if (matrix[i][j] == lookingFor)
	 //		{
	 //			cout << i << " " << j << endl;
	 //			counter++;
	 //		}
	 //	}
	 //}
	 //if (counter == 0) cout << "not found";

	//3
	//string line3; getline(cin, line3);
	//string line4; getline(cin, line4);
	//istringstream lineStream(line3);
	//istringstream lineStream2(line4);
	//vector<int> numbers;
	//vector<int> numbers2;
	//int currentNumber;
	//while (lineStream >> currentNumber) numbers.push_back(currentNumber);
	//while (lineStream2 >> currentNumber) numbers2.push_back(currentNumber);

	//vector<int> merged;
	//int min = INT_MIN;
	//int index = 0;
	//merged.push_back(min);
	//vector<char> mergedChar;
	//mergedChar.push_back('A');
	//for (int i = numbers.size() - 1; i >= 0; --i)
	//{
	//	for (int j = numbers2.size() - 1; j >= 0; --j)
	//	{
	//		if (merged[index] == INT_MIN)
	//		{
	//			if (numbers[i] < numbers2[j])
	//			{
	//				merged[index] = numbers[i];
	//				mergedChar[index] = 'A';
	//			}
	//			else
	//			{
	//				merged[index] = numbers2[j];
	//				mergedChar[index] = 'B';
	//			}
	//		}

	//		if (merged[index] < numbers[i])
	//		{
	//			bool willBreak = false;
	//			for (int k = numbers2.size() - 1; k >= 0; --k)
	//			{
	//				if (merged[index] < numbers2[k] && numbers2[k] < numbers[i])
	//				{
	//					index++;
	//					merged.push_back(numbers2[k]);
	//					mergedChar.push_back('B');
	//					willBreak = true;
	//					++i;
	//					break;
	//				}
	//			}
	//			if (willBreak)
	//			{
	//				continue;
	//			}
	//			merged.push_back(numbers[i]);
	//			mergedChar.push_back('A');
	//			index++;
	//			break;
	//		}
	//		if (merged[index] < numbers2[j])
	//		{
	//			bool willBreak = false;
	//			for (int l = numbers.size() - 1; l >= 0; --l)
	//			{
	//				if (merged[index] < numbers[l] && numbers[l] < numbers2[j])
	//				{
	//					index++;
	//					merged.push_back(numbers[l]);
	//					mergedChar.push_back('A');
	//					willBreak = true;
	//					++j;
	//					break;
	//				}
	//			}
	//			if (willBreak)
	//			{
	//				continue;
	//			}
	//			index++;
	//			merged.push_back(numbers2[j]);
	//			mergedChar.push_back('B');
	//		}


	//	}
	//}
	//for (int i = 0; i < mergedChar.size(); ++i)
	//{
	//	cout << mergedChar[i];
	//}
	//cout << endl;
	//for (int i = merged.size() - 1; i >= 0; --i)
	//{
	//	cout << merged[i] << " ";
	//}


	//string line;
	//getline(cin, line);
	//if (line[0] == '}' || line[0] == ']' || line[0] == ')')
	//{
	//	cout << "Invalid";
	//	return 0;
	//}

	//for (int i = 0; i < line.size(); ++i)
	//{
	//	char bracket = line[i];

	//	if (bracket == '{')
	//	{
	//		int index = line.find('}', i);
	//		if (index == -1)
	//		{
	//			cout << "invalid";
	//			return 0;
	//		}
	//	}
	//	else if (bracket == '[')
	//	{
	//		int index = line.find(']', i);
	//		if (index == -1)
	//		{
	//			cout << "invalid";
	//			return 0;
	//		}

	//		int a = line.substr(i , index - i).find('{');
	//		int b = line.substr(i , index - i).find('}');

	//		if (a > 0 || b > 0)
	//		{
	//			cout << "invalid";
	//			return 0;
	//		}
	//	}
	//	else if (bracket == '(')
	//	{
	//		int index = line.find(')', i);
	//		if (index == -1)
	//		{
	//			cout << "invalid";
	//			return 0;
	//		}
	//		int c = line.substr(i , index - i).find('{');
	//		int d = line.substr(i, index - i).find('}');
	//		int e = line.substr(i , index - i).find('[');
	//		int f = line.substr(i , index - i).find(']');
	//		if (c > 0 || d > 0 || e > 0 || f > 0)
	//		{
	//			cout << "invalid";
	//			return 0;
	//		}
	//	}
	//}
	//cout << "valid";
}



