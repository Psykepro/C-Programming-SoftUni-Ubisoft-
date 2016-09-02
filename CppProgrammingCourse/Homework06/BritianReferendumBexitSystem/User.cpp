#include "User.h"

/////////////////
// Constructor //
/////////////////

User::User(string newName, int newAge, Gender newGender, string newLivingPlace, string newEthnos)
{
	this->setName(newName);
	this->setAge(newAge);
	this->setGender(newGender);
	this->setLivingPlace(newLivingPlace);
	this->setEthnos(newEthnos);
}

/////////////
// Setters //
/////////////

void User::setName(string newName)
{
	if(newName == "")
	{
		throw invalid_argument("The name is invalid");
	}
	this->name = newName;
}

void User::setAge(int newAge)
{
	if (newAge == 0)
	{
		throw invalid_argument("The age is invalid");
	}
	this->age = newAge;
}

void User::setGender(Gender newGender)
{
	this->gender = newGender;
}

void User::setLivingPlace(string newLivingPlace)
{
	if (newLivingPlace == "")
	{
		throw invalid_argument("The living place is invalid");
	}
	this->livingPlace = newLivingPlace;
}

void User::setEthnos(string newEthnos)
{
	if (newEthnos == "")
	{
		throw invalid_argument("The ethnos is invalid");
	}
	this->ethnos = newEthnos;
}

/////////////
// Getters //
/////////////

string User::getName() const
{
	return this->name;
}

int User::getAge() const
{
	return this->age;
}

Gender User::getGender() const
{
	return this->gender;
}

string User::getLivingPlace() const
{
	return this->livingPlace;
}

string User::getEthnos() const
{
	return this->ethnos;
}
