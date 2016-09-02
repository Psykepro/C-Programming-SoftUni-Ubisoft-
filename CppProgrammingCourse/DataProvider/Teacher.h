#pragma once
#include "SoftUniParticipant.h"

class Teacher : public SoftUniParticipant
{
	float _monthlySalary;
	unsigned short _daysInSoftUni;
public:
	Teacher(unsigned short id, string name, Course course, float monthlySalary, unsigned short daysInSoftUni);
	~Teacher();
	float getMonthlySalary();
	void setMonthlySalary(float monthlySalary);
	unsigned short getDaysInSoftUni();
	void setDaysInSoftUni(unsigned short daysInSoftUni);
};

