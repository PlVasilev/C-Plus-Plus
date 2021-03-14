
#include "Defines.h"


#include <iostream>
#include <string>

ErrorCode decryptMessage(const std::string& commands,
	const char* leftBufferData,
	const size_t	   	 leftBufferSize,
	const char* rightBufferData,
	const size_t	   	 rightBufferSize,
	std::string& outMessage)
{
	if (commands.size() == 0)
	{
		return ErrorCode::DECRYPT_EMPTY;
	}

	bool allDecoded = true;


	for (int i = 0; i < commands.size(); i += 2)
	{
		int num = (commands[i + 1] - 48);
		if (commands[i] == 'r')
		{
			if (num >= rightBufferSize) {
				allDecoded = false;
				continue;
			}
			outMessage += rightBufferData[num];
		}
		if (commands[i] == 'l')
		{
			if (num >= leftBufferSize ) {
				allDecoded = false;
				continue;
			}
			outMessage += leftBufferData[num];
		}
	}
	if (allDecoded)
	{
		return ErrorCode::DECRYPT_SUCCESS;
	}
	return ErrorCode::DECRYPT_FAILURE;


};

void printResult(const ErrorCode     errorCode,
	const std::string& decryptedMessage)
{
	if (errorCode == ErrorCode::DECRYPT_SUCCESS)
	{
		std::cout << decryptedMessage << std::endl;
	}
	if (errorCode == ErrorCode::DECRYPT_EMPTY)
	{
		std::cout << "No input provided" << std::endl;
	}
	if (errorCode == ErrorCode::DECRYPT_FAILURE)
	{
		std::cout << decryptedMessage << " Warning, buffer out-of-bound detected" << std::endl;
	}
};