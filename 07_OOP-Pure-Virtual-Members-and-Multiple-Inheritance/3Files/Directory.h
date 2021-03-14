#ifndef DIRECTORY_CONTAINER_H
#define DIRECTORY_CONTAINER_H
#include <list>

using namespace std;

class Directory : public FileSystemObject, public FileSystemObjectsContainer {
	list<std::shared_ptr<FileSystemObject> > nestedObjects;
public:
	Directory(std::string name) : FileSystemObject(name) {}

	size_t getSize() const override {
		size_t size = 0;
		for (auto objPtr : this->nestedObjects) {
			size += objPtr->getSize();
		}

		return size;
	}

	void add(const std::shared_ptr<FileSystemObject>& obj) override {
		this->nestedObjects.push_back(obj);
	}
};

#endif // !DIRECTORY_CONTAINER_H