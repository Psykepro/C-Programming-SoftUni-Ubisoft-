#include "Total.h"
#include "Item.h"

class Item;

Total::Total(double value)
{
	this->setValue(value);
}

Total::~Total()
{
}

////////////////////////////
// Predefined += operator //
////////////////////////////
Total &Total::operator += (const Item &item)
{
	this->value += item.getValue();
	this->itemsForPurchase.push_back(item);
	
	return *this;
}

long double Total::getValue() const
{
	return this->value;
}

vector<Item> Total::getTtemsForPurchase() const
{
	return this->itemsForPurchase;
}

void Total::setValue(long double value)
{
	if(value < 0)
	{
		throw exception("Value must be positive double number");
	}
	else
	{
		this->value = value;
	}
}

void Total::clearTotal()
{
	this->setValue(0);
	this->itemsForPurchase.clear();
}
