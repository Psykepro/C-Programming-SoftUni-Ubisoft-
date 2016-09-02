#pragma once
#include <iostream>
#include "Object.h"

namespace MovementFramework
{
	class PhysicObject : public Object
	{
	private:
		string name;
		double mass;
		double jumpSpeed;
	public:
		/////////////////
		// Constructor //
		/////////////////
		PhysicObject(string newName, double newMass, double newJumpSpeed);

		////////////////
		// Destructor //
		////////////////
		virtual ~PhysicObject(){};

		/////////////
		// Setters //
		/////////////

		void setMass(double newMass);

		void setJumpSpeed(double newJumpSpeed);


		/////////////
		// Getters //
		/////////////

		double getMass() const;

		double getJumpSpeed() const;
	};
}

