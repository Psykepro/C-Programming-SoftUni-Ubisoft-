#pragma once
#include "User.h"

enum class Vote
{
	Stay = 0,
	Leave = 1
};

class Voter : public User
{
private:
	Vote vote;
public:
	Voter() {};
	Voter(string newName, int newAge, Gender newGender, string newLivingPlace, string newEthnos, Vote newVote);
	~Voter() {};

	/////////////
	// Setters //
	/////////////
	void setVote(Vote newVote);

	/////////////
	// Getters //
	/////////////
	Vote getVote() const;
};

