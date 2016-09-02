#pragma once
#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
	string registrationNumber;
	double weightInTones;
	short int numberOfSeats;
	string chassisNumber;
	string engineNumber;
	string owner;
public:
	Vehicle(string registrationNumber,
		double weightInTones,
		short int numberOfSeats,
		string chassisNumber,
		string engineNumber,
		string owner);
	~Vehicle();
};

