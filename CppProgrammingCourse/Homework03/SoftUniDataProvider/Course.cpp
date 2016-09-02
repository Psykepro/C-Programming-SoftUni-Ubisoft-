#include "Course.h"
#include <iostream>

using namespace std;

Course::Course(string name, int coursePoints)
{
	this->setName(name);
	this->setCoursePoints(coursePoints);
}


Course::~Course()
{
}

string Course::getName()
{
	return this->_name;
}

void Course::setName(string newName)
{
	this->_name = newName;
}

int Course::getCoursePoints()
{
	return this->_coursePoints;
}

void Course::setCoursePoints(int newCoursePoints)
{
	if(newCoursePoints > 100 || newCoursePoints < 0)
	{
		cout << "Course points must be between 0 and 100" << endl;
	}
	else
	{
		this->_coursePoints = newCoursePoints;
	}
}