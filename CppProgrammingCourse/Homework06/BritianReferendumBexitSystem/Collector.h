#pragma once
#include "User.h"
#include "Voter.h"
#include <memory>
#include <set>

class Collector : public User
{
	set<shared_ptr<Voter>> voters;
public:
	Collector(string newName, int newAge, Gender newGender, string newLivingPlace, string newEthnos);
	~Collector();
	void addVoter(const shared_ptr<Voter> &voter);
	void removeVoter(const shared_ptr<Voter> &voter);
	set<shared_ptr<Voter>> getVoters() const;
	void setVotersWithArray(const shared_ptr<Voter> voters[]);
};

