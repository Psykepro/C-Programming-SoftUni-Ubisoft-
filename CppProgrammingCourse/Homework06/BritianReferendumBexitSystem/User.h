#pragma once
#include <string>

using namespace std;

enum class Gender
{
	Female = 0,
	Male = 1
};

class User
{
private:
	string name;
	int age;
	Gender gender;
	string livingPlace;
	string ethnos;
public:
	User() {};
	User(string newName, int newAge, Gender newGender, string newLivingPlace, string newEthnos);
	~User() {};

	/////////////
	// Setters //
	/////////////
	void setName(string newName);
	void setAge(int newAge);
	void setGender(Gender newGender);
	void setLivingPlace(string newLivingPlace);
	void setEthnos(string newEthnos);
		
	/////////////
	// Getters //
	/////////////
	string getName() const;
	int getAge() const;
	Gender getGender() const;
	string getLivingPlace() const;
	string getEthnos() const;
};

