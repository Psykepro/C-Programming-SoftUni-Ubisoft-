#include "Item.h"
#include <iostream>

Item::Item(string name, double value, string BIC)
{
	this->setName(name);
	this->setValue(value);
	this->setBIC(BIC);
}

//////////////////////
// Copy Constructor //
//////////////////////
Item::Item(const Item &aItem)
{
	this->setName(aItem.getName());
	this->setValue(aItem.getValue());
	this->setBIC(aItem.getBIC());
}

Item::~Item()
{
}

void Item::setValue(double value)
{
	if (value < 0)
	{
		throw exception("The value of the item must be positive number");
	}
	else
	{
		this->value = value;
	}
}

void Item::setBIC(string BIC)
{
	if(BIC.length() < 10 || BIC.length() > 10)
	{
		throw exception("Items BIC must be long 10 characters");
	}
	else
	{
		this->BIC = BIC;
	}
}

void Item::setName(std::string name)
{
	if(name == "")
	{
		cout << "Name cannot be empty string" << endl;
	}
	else
	{
		this->name = name;
	}
}

double Item::getValue() const
{
	return this->value;
}

string Item::getBIC() const
{
	return this->BIC;
}

std::string Item::getName() const
{
	return this->name;
}
