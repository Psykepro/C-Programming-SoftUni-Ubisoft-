#include "Environment.h"

using namespace MovementFramework;

	/////////////////
	// Constructor //
	/////////////////

Environment::Environment(unsigned int newIdentifier, string newName, double newGravity)
{
	this->setIdentifier(newIdentifier);
	this->setName(newName);
	this->setGravity(newGravity);
}

	/////////////
	// Setters //
	/////////////

void Environment::setIdentifier(unsigned int newIdentifier)
{
	if (newIdentifier <= 0)
	{
		throw invalid_argument("Identifier is invalid.");
	}
	this->identifier = newIdentifier;
}

void Environment::setName(string newName)
{
	if (newName.length() == 0)
	{
		throw invalid_argument("Name is invalid.");
	}
	this->name = newName;
}

void Environment::setGravity(double newGravity)
{
	if (newGravity <= 0)
	{
		throw invalid_argument("Gravity is invalid.");
	}
	this->gravity = newGravity;
}

	/////////////
	// Getters //
	/////////////

unsigned int Environment::getIdentifier() const
{
	return this->identifier;
}

string Environment::getName() const
{
	return this->name;
}

double Environment::getGravity() const
{
	return this->gravity;
}


