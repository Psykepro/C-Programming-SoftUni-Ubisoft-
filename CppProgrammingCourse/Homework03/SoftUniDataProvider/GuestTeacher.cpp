#include "GuestTeacher.h"


GuestTeacher::GuestTeacher(unsigned short id, string name, Course course, float salaryForTheCourse) : SoftUniParticipant(id, name, course)
{
	this->setSalaryForTheCourse(salaryForTheCourse);
}

GuestTeacher::~GuestTeacher()
{
}

float GuestTeacher::getSalaryForTheCourse()
{
	return this->_salaryForTheCourse;
}

void GuestTeacher::setSalaryForTheCourse(float salaryForTheCourse)
{
	this->_salaryForTheCourse = salaryForTheCourse;
}
