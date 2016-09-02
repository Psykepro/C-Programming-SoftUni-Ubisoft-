#include <iostream>
#include <string>

using namespace std;

class Building
{
	string _name;
	int _floors;
	int _offices;
	long _employees;
	long _freeWorkSeats;

public:
	inline Building(string name, int floors, int offices, long employees, long freeWorkSeats)
	{
		this->setName(name);
		this->setFloors(floors);
		this->setOffices(offices);
		this->setEmployees(employees);
		this->setFreeWorkSeats(freeWorkSeats);
	}

	inline Building()
	{
		this->setName("No name");
		this->setFloors(0);
		this->setOffices(0);
		this->setEmployees(0);
		this->setFreeWorkSeats(0);
	}

	inline ~Building()
	{
		cout << "Destructor of building called" << endl;
	}

	inline void setName(string name)
	{
		this->_name = name;
	}

	inline string name()
	{
		return this->_name;
	}

	inline void setFloors(int floors)
	{
		this->_floors = floors;
	}

	inline int floors()
	{
		return this->_floors;
	}

	inline void setOffices(int offices)
	{
		this->_offices = offices;
	}

	inline int offices()
	{
		return this->_offices;
	}

	inline void setEmployees(long employees)
	{
		this->_employees = employees;
	}

	inline long employees()
	{
		return this->_employees;
	}

	inline void setFreeWorkSeats(long freeWorkSeats)
	{
		this->_freeWorkSeats = freeWorkSeats;
	}

	inline long freeWorkSeats()
	{
		return this->_freeWorkSeats;
	}
};

int main()
{
	Building bldg1 = Building("XYZ industries", 6, 127, 600, 196);
	Building bldg2 = Building("Rapid Development Crew", 8, 210, 822, 85);
	Building bldg3 = Building("SoftUni", 11, 106, 200, 60);
	Building businessPark[3];
	businessPark[0] = bldg1;
	businessPark[1] = bldg2;
	businessPark[2] = bldg3;

	string mostEmployeesBuildingName;
	long mostEmployees = INT64_MIN;
	string mostFreePlacesBuildingName;
	long mostFreePlaces = INT64_MIN;
	string highestCoefficientOfEmployeesBuildingName;
	double highestCoefficientOfEmployees = DBL_MIN;
	string mostPeoplePerFloorBuildingName;
	double mostPeoplePerFloor = DBL_MIN;
	string leastPeoplePerFloorBuildingName;
	double leastPeoplePerFloor = DBL_MAX;
	string mostOfficesPerFloorBuildingName;
	double mostOfficesPerFloor = DBL_MIN;
	string leastOfficesPerFloorBuildingName;
	double leastOfficesPerFloor = DBL_MAX;
	string mostPeoplePerOfficeBuildingName;
	double mostPeoplePerOffice = DBL_MIN;
	string leastPeoplePerOfficeBuildingName;
	double leastPeoplePerOffice = DBL_MAX;
	int length = sizeof(businessPark) / sizeof businessPark[0];

	for (int i = 0; i < length; i++)
	{
		Building currBldg = businessPark[i];

		// Find building with the most employees
		if (currBldg.employees() > mostEmployees)
		{
			mostEmployees = currBldg.employees();
			mostEmployeesBuildingName = currBldg.name();
		}

		// Find building with the most free work seats
		if (currBldg.freeWorkSeats() > mostFreePlaces)
		{
			mostFreePlaces = currBldg.freeWorkSeats();
			mostFreePlacesBuildingName = currBldg.name();
		}

		// Find building with the highest coefficient of employees
		double tempCoefficient = currBldg.employees() / (double)(currBldg.employees() + currBldg.freeWorkSeats());
		if (tempCoefficient > highestCoefficientOfEmployees)
		{
			highestCoefficientOfEmployees = tempCoefficient;
			highestCoefficientOfEmployeesBuildingName = currBldg.name();
		}

		// Find building with the most people per floor
		double floors = currBldg.floors();
		if (currBldg.name() == "Rapid Development Crew")
		{
			// Decrement with one, because building "Rapid Development Crew" have restaurant on the first floor
			floors -= 1;
		}
		double tempPeoplePerFloor = currBldg.employees() / floors;
		if (tempPeoplePerFloor > mostPeoplePerFloor)
		{
			mostPeoplePerFloor = tempPeoplePerFloor;
			mostPeoplePerFloorBuildingName = currBldg.name();
		}
		// Find building with the least people per floor
		if (tempPeoplePerFloor < leastPeoplePerFloor)
		{
			leastPeoplePerFloor = tempPeoplePerFloor;
			leastPeoplePerFloorBuildingName = currBldg.name();
		}

		// Find building with the most offices per floor
		double tempOfficesPerFloor = currBldg.offices() / floors;
		if (tempOfficesPerFloor > mostOfficesPerFloor)
		{
			mostOfficesPerFloor = tempOfficesPerFloor;
			mostOfficesPerFloorBuildingName = currBldg.name();
		}
		// Find building with the least offices per floor
		if (tempOfficesPerFloor < leastOfficesPerFloor)
		{
			leastOfficesPerFloor = tempOfficesPerFloor;
			leastOfficesPerFloorBuildingName = currBldg.name();
		}

		// Find building with the most people per office
		double tempPeoplePerOffice = currBldg.employees() / (double)currBldg.offices();
		if (tempPeoplePerOffice > mostPeoplePerOffice)
		{
			mostPeoplePerOffice = tempPeoplePerOffice;
			mostPeoplePerOfficeBuildingName = currBldg.name();
		}
		// Find building with the least people per office
		if (tempPeoplePerOffice < leastPeoplePerOffice)
		{
			leastPeoplePerOffice = tempPeoplePerOffice;
			leastPeoplePerOfficeBuildingName = currBldg.name();
		}
	}

	cout << "-(1)-Building with the most employees: " << mostEmployeesBuildingName << endl;
	cout << "-(2)-Building with the most free places: " << mostFreePlacesBuildingName << endl;
	cout << "-(3)-Building with the highest coefficient of employees: " << highestCoefficientOfEmployeesBuildingName << endl;
	cout << "-(4)-Building with the most people per floor: " << mostPeoplePerFloorBuildingName << endl;
	cout << "-(5)-Building with the least people per floor: " << leastPeoplePerFloorBuildingName << endl;
	cout << "-(6)-Building with the most offices per floor: " << mostOfficesPerFloorBuildingName << endl;
	cout << "-(7)-Building with the least offices per floor: " << leastOfficesPerFloorBuildingName << endl;
	cout << "-(8)-Building with the most people per office: " << mostPeoplePerOfficeBuildingName << endl;
	cout << "-(9)-Building with the least people per office: " << leastPeoplePerFloorBuildingName << endl;

	system("pause");
	return 0;
}
