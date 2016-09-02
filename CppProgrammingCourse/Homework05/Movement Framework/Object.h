#pragma once
#include <string>

namespace MovementFramework
{
	using namespace std;

	class Object
	{
		string name;
	public:
		/////////////////
		// Constructor //
		/////////////////

		Object(string newName);

		////////////////
		// Destructor //
		////////////////
		~Object(){};

		/////////////
		// Setters //
		/////////////

		void setName(string newName);

		/////////////
		// Getters //
		/////////////

		string getName() const;	
	};
}

