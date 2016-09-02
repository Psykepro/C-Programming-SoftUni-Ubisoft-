#include "Voter.h"

/////////////////
// Constructor //
/////////////////

Voter::Voter(string newName, int newAge, Gender newGender, string newLivingPlace, string newEthnos, Vote newVote) : User(newName, newAge, newGender, newLivingPlace, newEthnos)
{
	this->setVote(newVote);
}

/////////////
// Setters //
/////////////

void Voter::setVote(Vote newVote)
{
	this->vote = newVote;
}

/////////////
// Getters //
/////////////

Vote Voter::getVote() const
{
	return this->vote;
}
