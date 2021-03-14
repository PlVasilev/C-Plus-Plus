#ifndef EXPLORER_H
#define EXPLORER_H
#include <cstdlib>
#include <string>

#include "FileSystemObject.h"
#include "ByteContainer.h"

class Explorer
{
	std::vector<std::shared_ptr<FileSystemObject> > rootObjects;
public:
	Explorer(std::vector<std::shared_ptr<FileSystemObject> >& rootObjects): rootObjects(rootObjects) {  }

	void createFile(string& filename, string& contents)
	{
		
	}
};

#endif // !EXPLORER_H