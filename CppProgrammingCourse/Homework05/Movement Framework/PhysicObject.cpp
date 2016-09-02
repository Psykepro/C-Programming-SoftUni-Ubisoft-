#include "PhysicObject.h"
#include "Object.h"

using namespace MovementFramework;
using namespace std;

	/////////////////
	// Constructor //
	/////////////////

PhysicObject::PhysicObject(string newName, double newMass, double newJumpSpeed) : Object(newName)
{
	this->setName(newName);
	this->setMass(newMass);
	this->setJumpSpeed(newJumpSpeed);
}

	/////////////
	// Setters //
	/////////////

void PhysicObject::setMass(double newMass)
{
	if (newMass <= 0)
	{
		throw invalid_argument("Mass is invalid.");
	}
	this->mass = newMass;
}

void PhysicObject::setJumpSpeed(double newJumpSpeed)
{
	if (newJumpSpeed <= 0)
	{
		throw invalid_argument("Jump speed is invalid.");
	}
	this->jumpSpeed = newJumpSpeed;
}

	/////////////
	// Getters //
	/////////////

double PhysicObject::getMass() const
{
	return this->mass;
}

double PhysicObject::getJumpSpeed() const
{
	return this->jumpSpeed;
}