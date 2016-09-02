#include "Teacher.h"



Teacher::Teacher(unsigned short id, string name, Course course, float monthlySalary, unsigned short daysInSoftUni) : SoftUniParticipant(id, name, course)
{
	this->setMonthlySalary(monthlySalary);
	this->setDaysInSoftUni(daysInSoftUni);
}

Teacher::~Teacher()
{
}

float Teacher::getMonthlySalary()
{
	return this->_monthlySalary;
}

void Teacher::setMonthlySalary(float monthlySalary)
{
	this->_monthlySalary = monthlySalary;
}

unsigned short Teacher::getDaysInSoftUni()
{
	return this->_daysInSoftUni;
}

void Teacher::setDaysInSoftUni(unsigned short daysInSoftUni)
{
	this->_daysInSoftUni = daysInSoftUni;
}
