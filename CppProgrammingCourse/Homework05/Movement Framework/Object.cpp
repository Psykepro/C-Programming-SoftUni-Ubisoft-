#include "Object.h"

using namespace std;
using namespace MovementFramework;

	/////////////////
	// Constructor //
	/////////////////
Object::Object(string newName)
{
	this->setName(newName);
}

	/////////////
	// Setters //
	/////////////

void Object::setName(string newName)
{
	if (newName.length() == 0)
	{
		throw invalid_argument("Name is invalid.");
	}
	this->name = newName;
}

	/////////////
	// Getters //
	/////////////

string Object::getName() const
{
	return this->name;
}
