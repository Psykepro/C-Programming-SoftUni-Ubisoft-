#include <string>
#include "SoftUniParticipant.h"

using namespace std;

class Student : public SoftUniParticipant
{
	float _averageEvalMark;
	int _currentCoursePoints;
	void updateAverageEvalMark();
	void setAverageEvalMark(float newAverageEvalMark);
public:
	Student(unsigned short id, string name, Course course);
	~Student();
	float getAverageEvalMark();
	void addCourse(Course course);
	int getCurrentCoursePoints();
	void setCurrentCoursePoints(int coursePoints);
};
