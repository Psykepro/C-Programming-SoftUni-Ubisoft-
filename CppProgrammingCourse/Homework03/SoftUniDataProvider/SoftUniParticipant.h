#pragma once
#include "Course.h"
#include <vector>

using namespace std;

class SoftUniParticipant
{
	unsigned short _id;
	string _name;
	Course _currentCourse;
	vector<Course> _courses;
public:
	SoftUniParticipant(unsigned short id, string name, Course course);
	~SoftUniParticipant();
	unsigned short getId();
	void setId(unsigned short id);
	string getName();
	void setName(string name);
	Course getCurrentCourse();
	void setCurrentCourse(Course course);
	vector<Course> getCourses();
	void addCourse(Course course);
};

