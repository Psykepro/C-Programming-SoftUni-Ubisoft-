#include <iostream>
#include "SoftUniParticipant.h"
#include "Student.h"
#include "Teacher.h"
#include "GuestTeacher.h"
#include <iomanip>

using namespace  std;

void printDataForStudentById(vector<Student> students);
void printDataForTeacherById(vector<Teacher> teachers);
void printDataForGuestTeacherById(vector<GuestTeacher> guestTeachers);
void addNewStudent(int &currentStudentId, vector<Student> &students);
void addNewTeacher(int &currentTeacherId, vector<Teacher> &teachers);
void addNewGuestTeacher(int &currentGuestTeacherId, vector<GuestTeacher> &guestTeachers);

int main()
{
	int input = -1;
	int currentStudentId = 0;
	int currentTeacherId = 0;
	int currentGuestTeacherId = 0;
	vector<Student> students;
	vector<Teacher> teachers;
	vector<GuestTeacher> guestTeachers;

	while (input != 0)
	{
		cout << "To exit just write -> 0" << endl;
		cout << "Write the number of the actions which you want to do:" << endl;
		cout << "1. Get data for student with ID" << endl;
		cout << "2. Get data for teacher with ID" << endl;
		cout << "3. Get data for gest teacher with ID" << endl;
		cout << "4. Add data for new student" << endl;
		cout << "5. Add data for new teacher" << endl;
		cout << "6. Add data for new guest teacher" << endl;
		cin >> input;

		switch (input)
		{
		case 1:
			printDataForStudentById(students);
			break;
		case 2:
			printDataForTeacherById(teachers);
			break;
		case 3:
			printDataForGuestTeacherById(guestTeachers);
			break;
		case 4:
			addNewStudent(currentStudentId, students);
			system("cls");
			break;
		case 5:
			addNewTeacher(currentTeacherId, teachers);
			system("cls");
			break;
		case 6:
			addNewGuestTeacher(currentGuestTeacherId, guestTeachers);
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}

void printDataForStudentById(vector<Student> students)
{
	system("cls");
	int studentId;
	int neededStudentIndex = -1;
	int length = students.size();
	cout << "Enter student id (0-65535):" << endl;
	cin >> studentId;
	while(studentId < 0 || studentId > 65535)
	{
		cout << "Invalid student id! The id must be between 0 and 65535" << endl;
		cout << "Enter student id (0-65535):" << endl;
		cin >> studentId;
	}

	for (int i = 0; i < length; i++)
	{
		if(students[i].getId() == studentId)
		{
			neededStudentIndex = i;
		}
	}

	if(neededStudentIndex == -1)
	{
		cout << "No student exist with that ID." << endl;
	}
	else
	{
		system("cls");
		Student student = students[neededStudentIndex];
		cout << "<<<< Data for student with ID: " + to_string(studentId) + " >>>>" << endl;
		cout << "-   Id: " + to_string(student.getId()) << endl;
		cout << "-   Name: " + student.getName() << endl;
		cout << "-   Current course: " + student.getCurrentCourse().getName() << endl;
		cout << "-   Current points for the course: " + to_string(student.getCurrentCoursePoints()) << endl;
		cout << "-   Average evaluation mark: " << setprecision(3) << student.getAverageEvalMark() << endl << endl;
	}
}

void printDataForTeacherById(vector<Teacher> teachers)
{
	system("cls");
	int teacherId;
	int neededTeacherIndex = -1;
	int length = teachers.size();
	cout << "Enter teacher id (0-65535):" << endl;
	cin >> teacherId;
	while (teacherId < 0 || teacherId > 65535)
	{
		cout << "Invalid teacher id! The id must be between 0 and 65535" << endl;
		cout << "Enter teacher id (0-65535):" << endl;
		cin >> teacherId;
	}

	for (int i = 0; i < length; i++)
	{
		if (teachers[i].getId() == teacherId)
		{
			neededTeacherIndex = i;
		}
	}

	if (neededTeacherIndex == -1)
	{
		cout << "No teacher exist with that ID." << endl;
	}
	else
	{
		system("cls");
		Teacher teacher = teachers[neededTeacherIndex];
		cout << "<<<< Data for teacher with ID: " + to_string(teacherId) + " >>>>" << endl;
		cout << "-   Id: " + to_string(teacher.getId()) << endl;
		cout << "-   Name: " + teacher.getName() << endl;
		cout << "-   Current course: " + teacher.getCurrentCourse().getName() << endl;
		cout << "-   Monthly salary: " << setprecision(2) << to_string(teacher.getMonthlySalary()) << endl;
		cout << "-   Days passed since the teacher joined SoftUni: " << teacher.getDaysInSoftUni() << endl << endl;
	}
}

void printDataForGuestTeacherById(vector<GuestTeacher> guestTeachers)
{
	system("cls");
	int guestTeacherId;
	int neededGuestTeacherIndex = -1;
	int length = guestTeachers.size();
	cout << "Enter teacher id (0-65535):" << endl;
	cin >> guestTeacherId;
	while (guestTeacherId < 0 || guestTeacherId > 65535)
	{
		cout << "Invalid guest teacher id! The id must be between 0 and 65535" << endl;
		cout << "Enter guest teacher id (0-65535):" << endl;
		cin >> guestTeacherId;
	}

	for (int i = 0; i < length; i++)
	{
		if (guestTeachers[i].getId() == guestTeacherId)
		{
			neededGuestTeacherIndex = i;
		}
	}

	if (neededGuestTeacherIndex == -1)
	{
		cout << "No guest teacher exist with that ID." << endl;
	}
	else
	{
		system("cls");
		GuestTeacher guestTeacher = guestTeachers[neededGuestTeacherIndex];
		cout << "<<<< Data for teacher with ID: " + to_string(guestTeacherId) + " >>>>" << endl;
		cout << "-   Id: " + to_string(guestTeacher.getId()) << endl;
		cout << "-   Name: " + guestTeacher.getName() << endl;
		cout << "-   Current course: " + guestTeacher.getCurrentCourse().getName() << endl;
		cout << "-   Salary for the course: " << setprecision(2) << to_string(guestTeacher.getSalaryForTheCourse()) << endl << endl;
	}
}

void addNewStudent(int &currentStudentId, vector<Student> &students)
{
	system("cls");
	cout << "Creating new student:" << endl;
	int studentId = currentStudentId;
	currentStudentId++;
	string studentName;
	cout << "Name:" << endl;
	cin.ignore();
	getline(cin, studentName);

	string currentCourseName;
	cout << "Current course name:" << endl;
	getline(cin, currentCourseName);

	int currentCoursePoints;
	cout << "Current course points:" << endl;
	cin >> currentCoursePoints;
	if (currentCoursePoints > 100)
	{
		currentCoursePoints = 100;
	}
	else if(currentCoursePoints < 0)
	{
		currentCoursePoints = 0;
	}

	Student newStudent(studentId, studentName, Course(currentCourseName, currentCoursePoints));

	int coursesCount;
	cout << "Write how much other courses the student have:" << endl;
	cin >> coursesCount;
	if (coursesCount > 0)
	{
		cout << "Write course name and course points for each of them:" << endl;
		for (int i = 0; i < coursesCount; i++)
		{
			cout << "Current course name:" << endl;
			cin.ignore();
			getline(cin, currentCourseName);
			cout << "Current course points:" << endl;
			cin >> currentCoursePoints;
			if (currentCoursePoints > 100)
			{
				currentCoursePoints = 100;
			}
			else if (currentCoursePoints < 0)
			{
				currentCoursePoints = 0;
			}
			newStudent.addCourse(Course(currentCourseName, currentCoursePoints));
		}
	}
	students.push_back(newStudent);
}
void addNewTeacher(int &currentTeacherId, vector<Teacher> &teachers)
{
	system("cls");
	cout << "Creating new teacher:" << endl;
	int teacherId = currentTeacherId;
	currentTeacherId++;
	string teacherName;
	cout << "Name:" << endl;
	cin.ignore();
	getline(cin, teacherName);

	string currentCourseName;
	cout << "Current course name:" << endl;
	getline(cin, currentCourseName);

	float monthlySalary;
	cout << "Monthly salary:" << endl;
	cin >> monthlySalary;

	int daysInSoftUni;
	cout << "How many days have passed since he joined SoftUni (0 - 65535):" << endl;
	cin >> daysInSoftUni;

	Teacher newTeacher(teacherId, teacherName, Course(currentCourseName), monthlySalary, daysInSoftUni);
	teachers.push_back(newTeacher);
}
void addNewGuestTeacher(int &currentGuestTeacherId, vector<GuestTeacher> &guestTeachers)
{
	system("cls");
	cout << "Creating new guest teacher:" << endl;
	int guestTeacherId = currentGuestTeacherId;
	currentGuestTeacherId++;
	string guestTeacherName;
	cout << "Name:" << endl;
	cin.ignore();
	getline(cin, guestTeacherName);

	string currentCourseName;
	cout << "Current course name:" << endl;
	getline(cin, currentCourseName);

	float salaryForTheCourse;
	cout << "Salary for the course:" << endl;
	cin >> salaryForTheCourse;

	GuestTeacher newGuestTeacher(guestTeacherId, guestTeacherName, Course(currentCourseName), salaryForTheCourse);
	guestTeachers.push_back(newGuestTeacher);
}
