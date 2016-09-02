#include "PhysicController.h"

using namespace MovementFramework;

double PhysicController::calculateMaximumJumpHeight(const PhysicObject& aPhysicObject, const Environment &aEnvironment)
{	
	double jumpSpeedToMetersPerSecond = aPhysicObject.getJumpSpeed() / 3.6;
	double maximumHeight = pow(jumpSpeedToMetersPerSecond, 2.0) / 2 * aEnvironment.getGravity();
	return maximumHeight;
}

double PhysicController::calculateTimeOfJump(const PhysicObject& aPhysicObject, const Environment& aEnvironment)
{
	double jumpSpeedToMetersPerSecond = aPhysicObject.getJumpSpeed() / 3.6;
	double timeOfJump = (2 * jumpSpeedToMetersPerSecond) / aEnvironment.getGravity();
	return timeOfJump;
}

bool PhysicController::checkIsAbleToJumpOnGivenHeight(double heightToJump, const const PhysicObject& aPhysicObject, const Environment& aEnvironment)
{
	double maxJumpHeight = calculateMaximumJumpHeight(aPhysicObject, aEnvironment);
	bool result = maxJumpHeight >= heightToJump;
	return result;
}
