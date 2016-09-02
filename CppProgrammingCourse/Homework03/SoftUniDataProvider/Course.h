#pragma once
#include <string>

using namespace std;

class Course
{
	string _name;
	int _coursePoints;
public:
	Course(string name = "", int coursePoints = 0);
	~Course();
	string getName();
	void setName(string newName);
	int getCoursePoints();
	void setCoursePoints(int newCoursePoints);
};

