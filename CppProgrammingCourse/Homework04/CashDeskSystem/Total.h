#pragma once
#include <vector>
class Item;

using namespace std;

class Total
{
	long double value;
	vector<Item> itemsForPurchase;
public:
	Total(double value = 0);
	~Total();
	Total &operator += (const Item &item);
	long double getValue() const;
	vector<Item> getTtemsForPurchase() const;
	void setValue(long double value);
	void clearTotal();
};

