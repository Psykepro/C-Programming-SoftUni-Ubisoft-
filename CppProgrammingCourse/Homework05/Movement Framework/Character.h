#pragma once
#include <string>
#include "PhysicObject.h"

namespace MovementFramework
{
	using namespace std;
	class Character : public PhysicObject
	{
		unsigned int identifier;
	public:
		/////////////////
		// Constructor //
		/////////////////

		Character(string newName, double newMass, double newJumpSpeed, unsigned int newIdentifier);

		////////////////
		// Destructor //
		////////////////

		~Character() {};

		/////////////
		// Getters //
		/////////////

		unsigned int getIdentifier() const;
	};
}



