#include "Collector.h"


Collector::Collector(string newName, int newAge, Gender newGender, string newLivingPlace, string newEthnos) : User(newName, newAge, newGender, newLivingPlace, newEthnos)
{
}


Collector::~Collector()
{
}

set<shared_ptr<Voter>> Collector::getVoters() const
{
	return this->voters;
}

void Collector::setVotersWithArray(const shared_ptr<Voter> newVoters[])
{
	this->voters = set<shared_ptr<Voter>>(newVoters, newVoters + (sizeof(newVoters) / sizeof(newVoters[0])));
}

void Collector::addVoter(const shared_ptr<Voter> &voter)
{
	this->voters.insert(voter);
}

void Collector::removeVoter(const shared_ptr<Voter> &voter)
{
	this->voters.erase(voter);
}


