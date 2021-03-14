#ifndef SERIALIZE_H
#define SERIALIZE_H

using namespace std;

byte* serializeToMemory(const string& input, size_t& bytesWritten)
{
	byte* memory = new byte[input.size()];
	bytesWritten = 0;
	int lines = 0;
	bool isNumber = true;
	memory[bytesWritten] = 0;
	int currentNumber = 0;
	int start = 0;
	int counter = 0;
	
	for (int i = 0; i < input.size(); i++) {
		
		if (input[i] == 10)
		{
			lines++;
			isNumber = true;
			continue;
		}
		if (isNumber == true && input[i] == 32)
		{
			isNumber = false;
			bytesWritten++;
			memory[bytesWritten] = currentNumber;
			currentNumber = 0;
			continue;
		}
		if (input[i] == '(')
		{
			counter = 0;
			bytesWritten++;
			memory[bytesWritten] = 0;
			bytesWritten++;
			start = bytesWritten;
			memory[bytesWritten] = 0;
		}
		if (input[i] == ')')
		{
			memory[start] = counter / 2;
		}
		if (input[i] < 47)
		{
			continue;
		}
		if (isNumber)
		{
			currentNumber = currentNumber * 10 + (input[i] - '0');
		}
		else
		{
			counter++;
			bytesWritten++;
			memory[bytesWritten] = input[i];
		}
		
	}

	memory[0] = lines;
	bytesWritten++;
	
	return memory;
	
}

#endif // !SERIALIZE_H
