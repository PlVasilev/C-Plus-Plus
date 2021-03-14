#include <iostream>

#include "Defines.h"
#include <string>
#include <vector>

using namespace std;

ErrorCode executeCommand(const std::string& command,
                         std::vector<MemoryNode>& memory)
{
	const string commandStr = command.substr(0, command.size() - 2);
	int index = stoi(command.substr(command.size() - 1, command.size()));
	if (commandStr == "Allocate Single")
	{
		if (memory[index].memoryType == MemoryType::UNKNOWN)
		{
			memory[index].memoryType = MemoryType::SINGLE;
			return ErrorCode::EXECUTE_SUCCESS;
		}
		if(memory[index].memoryType == MemoryType::SINGLE || memory[index].memoryType == MemoryType::MULTIPLE)
		{
			return ErrorCode::MEMORY_LEAK;
		}
	}
	if (commandStr == "Deallocate Single")
	{
		if (memory[index].memoryType == MemoryType::SINGLE)
		{
			memory[index].memoryType = MemoryType::UNKNOWN;
			return ErrorCode::EXECUTE_SUCCESS;
		}
		if (memory[index].memoryType == MemoryType::UNKNOWN)
		{
			return ErrorCode::DOUBLE_FREE;
		}
		if (memory[index].memoryType == MemoryType::MULTIPLE)
		{
			return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;
		}
	}
	if (commandStr == "Allocate Multiple")
	{
		if (memory[index].memoryType == MemoryType::UNKNOWN)
		{
			memory[index].memoryType = MemoryType::MULTIPLE;
			return ErrorCode::EXECUTE_SUCCESS;
		}
		if (memory[index].memoryType == MemoryType::SINGLE || memory[index].memoryType == MemoryType::MULTIPLE)
		{
			return ErrorCode::MEMORY_LEAK;
		}
	}
	if (commandStr == "Deallocate Multiple")
	{
		if (memory[index].memoryType == MemoryType::MULTIPLE)
		{
			memory[index].memoryType = MemoryType::UNKNOWN;
			return ErrorCode::EXECUTE_SUCCESS;
		}
		if (memory[index].memoryType == MemoryType::UNKNOWN)
		{
			return ErrorCode::DOUBLE_FREE;
		}
		if (memory[index].memoryType == MemoryType::SINGLE)
		{
			return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;
		}
	}

	return ErrorCode::EXECUTE_SUCCESS;
};

void printResult(const ErrorCode     errorCode,
    const std::string& command)
{
	if (errorCode == ErrorCode::EXECUTE_SUCCESS)
	{
		cout << command << " - success" << endl;
	}
	if (errorCode == ErrorCode::DOUBLE_FREE)
	{
		cout << command << " - system crash prevented, will skip this deallocation" << endl;
	}
	if (errorCode == ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH)
	{
		cout << command << " - Warning allocate/deallocate mismatch, will skip this deallocation" << endl;
	}
	if (errorCode == ErrorCode::MEMORY_LEAK)
	{
		cout << command << " - memory leak prevented, will not make allocation" << endl;
	}
};