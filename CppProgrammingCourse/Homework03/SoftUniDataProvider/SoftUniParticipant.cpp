#include "SoftUniParticipant.h"
#include <iostream>


SoftUniParticipant::SoftUniParticipant(unsigned short id, string name, Course course)
{
	this->setId(id);
	this->setName(name);
	this->setCurrentCourse(course);
	this->addCourse(course);
}


SoftUniParticipant::~SoftUniParticipant()
{
}

unsigned short SoftUniParticipant::getId()
{
	return this->_id;
}

void SoftUniParticipant::setId(unsigned short id)
{
	this->_id = id;
}

string SoftUniParticipant::getName()
{
	return this->_name;
}

void SoftUniParticipant::setName(string name)
{
	this->_name = name;
}

Course SoftUniParticipant::getCurrentCourse()
{
	return this->_currentCourse;
}

void SoftUniParticipant::setCurrentCourse(Course course)
{
	this->_currentCourse = course;
}

vector<Course> SoftUniParticipant::getCourses()
{
	return this->_courses;
}
void SoftUniParticipant::addCourse(Course course)
{
	this->_courses.push_back(course);
}

