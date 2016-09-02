#pragma once
#include "Character.h"
#include "Environment.h"

namespace MovementFramework
{
	class PhysicController
	{
	public:
		PhysicController(){};
		static double calculateMaximumJumpHeight(const PhysicObject& aPhysicObject, const Environment &aEnvironment);
		static double calculateTimeOfJump(const PhysicObject& aPhysicObject, const Environment &aEnvironment);
		static bool checkIsAbleToJumpOnGivenHeight(double heightToJump, const PhysicObject& aPhysicObject, const Environment &aEnvironment);
	};
}


