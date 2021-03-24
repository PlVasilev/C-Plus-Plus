

#include <iostream>
#include <array>

using namespace std;

int main()
{
	//											LONGEST SEQUENCE
	//array<int, 100> arr = { 0 };

	//int num;
	//cin >> num;



	//for (int i = 0; i < num; ++i)
	//{
	//	int current;
	//	cin >> current;
	//	arr[i] = current;
	//}

	//int longestArr = 0;
	//int longestArrVal = 0;
	//int currentArr = 0;
	//int currentArrVal = 0;



	//for (int i = 0; i < num; ++i)
	//{
	//	if (i == 0)
	//	{
	//		longestArr = 1;
	//		longestArrVal = arr[i];
	//		currentArr = 1;
	//		currentArrVal = arr[i];
	//	}
	//	else
	//	{
	//		if (arr[i] == arr[i + 1])
	//		{
	//			currentArr++;
	//			currentArrVal = arr[i];
	//		}
	//		else
	//		{
	//			if (currentArr >= longestArr)
	//			{
	//				longestArrVal = currentArrVal;
	//				longestArr = currentArr;
	//			}
	//			currentArr = 1;
	//			currentArrVal = arr[i + 1];
	//		}
	//	}
	//}

	//for (int i = 0; i < longestArr; ++i)
	//{
	//	cout << longestArrVal << " ";
	//}


	//											ABOVE AVERAGE
	//array<int, 100> arr = { 0 };

	//int num;
	//cin >> num;
	//int average = 0;

	//for (int i = 0; i < num; ++i)
	//{
	//	int current;
	//	cin >> current;
	//	arr[i] = current;
	//	average += current;
	//}

	//average /= num;

	//for (int i = 0; i < num; ++i)
	//{
	//	if (arr[i] >= average)
	//	{
	//		cout << arr[i] << " ";
	//	}
	//}

	//												Most Frequent Number
	//array<int, 100> arr = { 0 };
	//array<int, 10> result = { 0,0,0,0,0,0,0,0,0,0 };

	//int num;
	//cin >> num;
	//int average = 0;

	//for (int i = 0; i < num; ++i)
	//{
	//	int current;
	//	cin >> current;
	//	switch (current)
	//	{
	//	case 0: result[0]++; break;
	//	case 1: result[1]++; break;
	//	case 2: result[2]++; break;
	//	case 3: result[3]++; break;
	//	case 4: result[4]++; break;
	//	case 5: result[5]++; break;
	//	case 6: result[6]++; break;
	//	case 7: result[7]++; break;
	//	case 8: result[8]++; break;
	//	case 9: result[9]++; break;
	//	default: break;
	//	}
	//}

	//int mostRepeats = 0;

	//for (int i : result) { if (i > mostRepeats) mostRepeats = i; }

	//for (int i = 0; i < result.size(); ++i)
	//{
	//	if (result[i] == mostRepeats) cout << i << " ";	
	//}

	array<long, 10000> arr = { 0 };

	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		int current;
		cin >> current;
		arr[i] = current;
	}

	int result = LONG_MAX;

	if (num == 1)
	{
		result = 0;
	}
	else {

		for (int i = 0; i < num; ++i)
		{
			for (int j = 0; j < num; ++j)
			{
				if (i == j)
				{
					continue;
				}
				const int current = abs(arr[i] - arr[j]);
				if (current < result)
				{
					result = current;
				}
			}
		}
	}

	cout << result;

}


