#include "Character.h"

using namespace MovementFramework;

static unsigned int currentCharacterId = 0;

	/////////////////
	// Constructor //
	/////////////////

Character::Character(string newName, double newMass, double newJumpSpeed, unsigned int newIdentifier) : PhysicObject(newName, newMass, newJumpSpeed)
{
	currentCharacterId++;
	this->identifier = currentCharacterId;
}

	/////////////
	// Getters //
	/////////////

unsigned int Character::getIdentifier() const
{
	return this->identifier;
}
