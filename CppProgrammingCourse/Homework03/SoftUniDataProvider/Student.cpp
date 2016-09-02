#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(unsigned short id, string name, Course course) : SoftUniParticipant(id, name, course)
{
	this->setCurrentCoursePoints(this->getCurrentCourse().getCoursePoints());
}

Student::~Student()
{
}

float Student::getAverageEvalMark()
{
	return this->_averageEvalMark;
}

void Student::setAverageEvalMark(float newAverageEvalMark)
{
	this->_averageEvalMark = newAverageEvalMark;
}

void Student::addCourse(Course course)
{
	SoftUniParticipant::addCourse(course);
	updateAverageEvalMark();
}

int Student::getCurrentCoursePoints()
{
	return this->_currentCoursePoints;
}

void Student::setCurrentCoursePoints(int coursePoints)
{
	this->_currentCoursePoints = coursePoints;
}

void Student::updateAverageEvalMark()
{
	const int length = this->getCourses().size();
	float averageGrade = 0;

	if (length > 1)
	{
		int sumOfAllCoursePoints = 0;
		vector<Course> courses = this->getCourses();
		for (int i = 0; i < length; i++)
		{
			sumOfAllCoursePoints += courses[i].getCoursePoints();
		}

		int averageSumOfAllCoursePoints = sumOfAllCoursePoints / length;
		if (averageSumOfAllCoursePoints <= 20)
		{
			averageGrade += 2.0;
		}
		else if (averageSumOfAllCoursePoints > 20 && averageSumOfAllCoursePoints <= 39)
		{
			averageSumOfAllCoursePoints -= 20;
			averageGrade += 2 + (averageSumOfAllCoursePoints / double(20));
		}
		else if (averageSumOfAllCoursePoints >= 40 && averageSumOfAllCoursePoints <= 59)
		{
			averageSumOfAllCoursePoints -= 40;
			averageGrade += 3 + (averageSumOfAllCoursePoints / double(20));
		}
		else if (averageSumOfAllCoursePoints >= 60 && averageSumOfAllCoursePoints <= 79)
		{
			averageSumOfAllCoursePoints -= 60;
			averageGrade += 4 + (averageSumOfAllCoursePoints / double(20));
		}
		else if (averageSumOfAllCoursePoints >= 80 && averageSumOfAllCoursePoints <= 99)
		{
			averageSumOfAllCoursePoints -= 80;
			averageGrade += 5 + (averageSumOfAllCoursePoints / double(20));
		}
		else if (averageSumOfAllCoursePoints == 100)
		{
			averageGrade += 6;
		}
	}

	this->setAverageEvalMark(averageGrade);
}


