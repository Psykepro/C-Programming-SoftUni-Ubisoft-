#pragma once
#include <string>

using namespace std;

class Item
{
	std::string name;
	double value;
	string BIC;
public:
	Item(string name = "Defalut Name", double value = 1, string BIC = "0000000000");
	Item(const Item &aItem);
	~Item();
	void setValue(double value);
	void setBIC(string BIC);
	void setName(string name);
	double getValue() const;
	string getBIC() const;
	string getName() const;
};

