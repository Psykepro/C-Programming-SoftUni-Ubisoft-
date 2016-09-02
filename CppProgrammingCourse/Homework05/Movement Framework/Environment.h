#pragma once
#include <string>

namespace MovementFramework
{
	using namespace std;

	class Environment
	{
		unsigned int identifier;
		string name;
		double gravity; // gravity in m/s
	public:
		/////////////////////////
		// Default Constructor //
		/////////////////////////

		Environment() {};

		/////////////////
		// Constructor //
		/////////////////

		Environment(unsigned int newIdentifier, string newName, double newGravity);

		////////////////
		// Destructor //
		////////////////

		~Environment() {};

		/////////////
		// Setters //
		/////////////

		void setName(string newName);

		void setGravity(double newGravity);

		void setIdentifier(unsigned int newIdentifier);

		/////////////
		// Getters //
		/////////////

		string getName() const;

		double getGravity() const;

		unsigned int getIdentifier() const;
	};
}

