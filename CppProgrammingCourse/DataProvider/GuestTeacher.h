#pragma once
#include "SoftUniParticipant.h"

class GuestTeacher : public SoftUniParticipant
{
	float _salaryForTheCourse;
public:
	GuestTeacher(unsigned short id, string name, Course course, float salaryForTheCourse);
	~GuestTeacher();
	float getSalaryForTheCourse();
	void setSalaryForTheCourse(float salaryForTheCourse);
};

