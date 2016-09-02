#include <iostream>
#include "Character.h"
#include "Environment.h"
#include "PhysicController.h"

#define EARTH_GRAVITY 9.81

using namespace std;
using namespace MovementFramework;

int main()
{
	Character johny("Johny", 50, 7.02, 1);
	Environment earth(1, "Earth", EARTH_GRAVITY);

	cout << "Maximum jump height: " << PhysicController::calculateMaximumJumpHeight(johny, earth) << endl;
	cout << "Time in the air: " << PhysicController::calculateTimeOfJump(johny, earth) << endl;
	string checkResult = PhysicController::checkIsAbleToJumpOnGivenHeight(12.0, johny, earth) ? "True" : "False";
	cout << "Check is able to jump on height - 12 meters : " << checkResult << endl;

	system("pause");
	return 0;
}