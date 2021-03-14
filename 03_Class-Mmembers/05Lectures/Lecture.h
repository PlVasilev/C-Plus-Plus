#ifndef LECTURE_H
#define LECTURE_H

#include "ResourceType.h"
#include "Resource.h"
#include "Lecture.h"
using namespace std;

namespace SoftUni {
	class Lecture
	{
		std::set<Resource> resources;
		int types[];
		
	public:
		Lecture()
		{
			
		};
		Lecture& operator<<(const Resource& r)
		{
			this->resources.insert(r);
			return *this;
		}

		std::set<Resource>::iterator begin() const
		{
			return this->resources.begin();
		}

		std::set<Resource>::iterator end() const
		{
			return this->resources.end();
		}

		
	};



}


#endif // !LECTURE_H
