#ifndef RESOURCE_H
#define RESOURCE_H

#include <ostream>
#include <string>
#include <sstream>
#include "ResourceType.h"

namespace SoftUni {
	class Resource
	{
	private:
		int id;
		ResourceType resourceType;
		std::string link;
	public:

		Resource() = default;

		const ResourceType getType() const
		{
			return this->resourceType;
		}

		bool operator<(const Resource& other) const {
			return this->id < other.id;
		}

		friend std::istream& operator>>(std::istream& input, Resource& r);

		friend std::ostream& operator<<(std::ostream& output, const Resource& r);
	};

	std::ostream& operator<<(std::ostream& output, const Resource& r) {

		return  output << r.id << " " << r.resourceType << " " << r.link;
	}

	std::istream& operator>>(std::istream& in, ResourceType& resourceType) {
		std::string type;
		in >> type;
		if (type == "Presentation") {
			resourceType = ResourceType::PRESENTATION;
		}
		else if (type == "Demo") {
			resourceType = ResourceType::DEMO;
		}
		else if (type == "Video") {
			resourceType = ResourceType::VIDEO;
		}
		return in;
	}

	std::istream& operator>>(std::istream& input, Resource& r) {
		return input >> r.id >> r.resourceType >> r.link;
	}
}

#endif // !RESOURCE_H