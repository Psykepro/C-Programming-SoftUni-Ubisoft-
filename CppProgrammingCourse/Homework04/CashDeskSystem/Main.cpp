#include <iostream>
#include <string>
#include "Item.h"
#include <vector>
#include "Total.h"
#include <cstdlib>

using namespace std;
string padTo(string str, const size_t num, const char paddingChar = ' ');
void addItemToTotal(vector<Item> items);
int checkForItem(string BIC, vector<Item> items);
void changeItemValue(vector<Item> &items);
void clearTotal();
void continueMessage();
void printTotalValue();
void makePurchase();
double validatedDoubleParsing(string input);

///////////////////////////////////////////////////////////////////////////////////
// Total is globally declared to use it everywhere, because we need only 1 total //
///////////////////////////////////////////////////////////////////////////////////
Total total(0);

//////////////////////////////////
// Same for the customerAddress //
//////////////////////////////////
string customerAddress = "Somewhere in the middle of nowhere";

int main()
{
	////////////////////////
	// Hardcode the items //
	////////////////////////
	string currentBic;

	vector<Item> items;
	int currentBicCounter = 0;
	currentBic = padTo(to_string(++currentBicCounter), 10, '0');
	items.push_back(Item("Monitor", 200.50, currentBic));
	currentBic = padTo(to_string(++currentBicCounter), 10, '0');
	items.push_back(Item("Beer", 3.50, currentBic));
	currentBic = padTo(to_string(++currentBicCounter), 10, '0');
	items.push_back(Item("Book", 50.0, currentBic));
	currentBic = padTo(to_string(++currentBicCounter), 10, '0');
	items.push_back(Item("Gaming Keyboard", 130, currentBic));
	currentBic = padTo(to_string(++currentBicCounter), 10, '0');
	items.push_back(Item("Laptop", 1600.50, currentBic));


	cout << "Type the needed character to fire function:" << endl;
	cout << "A <-- to add item to the total" << endl;
	cout << "V <-- to change item's value" << endl;
	cout << "C <-- to clear the total" << endl;
	cout << "T <-- to display total's value" << endl;
	cout << "G <-- to purchase the items added to the total" << endl;
	cout << "E <-- to close the program." << endl;
	string input;
	getline(cin, input);
	while (input[0] != 'E')
	{
		switch (input[0])
		{
		case 'A':
			addItemToTotal(items);
			break;
		case 'V':
			changeItemValue(items);
			break;
		case 'C':
			clearTotal();
			break;
		case 'T':
			printTotalValue();
			break;
		case 'G':
			makePurchase();
			break;
		}

		system("cls");
		cout << "Type the needed character to fire function:" << endl;
		cout << "A <-- to add item to the total" << endl;
		cout << "V <-- to change item's value" << endl;
		cout << "C <-- to clear the total" << endl;
		cout << "T <-- to display total's value" << endl;
		cout << "G <-- to purchase the items added to the total" << endl;
		cout << "E <-- to close the program." << endl;
		getline(cin, input);

	}
	system("pause");
	return 0;
}

string padTo(string str, const size_t num, const char paddingChar)
{
	if (num > str.size())
		str.insert(0, num - str.size(), paddingChar);
	return str;
}

void addItemToTotal(vector<Item> items)
{
	system("cls");
	cout << "Write 10-digit code to add item by BIC code to the total:" << endl;
	string input;
	getline(cin, input);

	while (input.length() < 10 || input.length() > 10)
	{
		system("cls");
		cout << "Write 10-digit code to add item by BIC code to the total:" << endl;
		getline(cin, input);
	}


	int isItemExist = checkForItem(input, items);
	if (isItemExist == -1)
	{
		system("cls");
		cout << "Item cannot be found" << endl;
		void continueMessage();

		return;
	}

	total += items[isItemExist];
}

void changeItemValue(vector<Item> &items)
{
	system("cls");
	cout << "Write the BIC code (10 digits) to get the item which you want to change:" << endl;
	string input;
	getline(cin, input);
	while (input.length() < 10 || input.length() > 10)
	{
		system("cls");
		cout << input.length() << endl;
		cout << "Write the BIC code (10 digits) to get the item which you want to change:" << endl;
		getline(cin, input);
	}

	int isItemExist = checkForItem(input, items);

	if (isItemExist == -1)
	{
		system("cls");
		cout << "Item cannot be found" << endl;
		void continueMessage();
	}
	else
	{
		system("cls");
		Item itemToChange(items[isItemExist]);
		cout << ">>> Information for the Item <<<" << endl;
		cout << "Name : " << itemToChange.getName() << endl;
		cout << "Value : ";
		printf("%.2fleva\n", itemToChange.getValue());
		cout << "BIC : " << itemToChange.getBIC() << endl;
		double newValue = validatedDoubleParsing(input);

		items[isItemExist].setValue(newValue);
	}
}

void clearTotal()
{
	system("cls");
	total.clearTotal();
	cout << ">>> Total cleared <<<" << endl;
	continueMessage();
}

int checkForItem(string BIC, vector<Item> items)
{
	int length = items.size();
	for (int i = 0; i < length; i++)
	{
		if (items[i].getBIC() == BIC)
		{
			return i;
		}
	}

	return -1;
}

void printTotalValue()
{
	system("cls");
	cout << ">>> Total value <<<" << endl;
	printf("%.2fleva\n", total.getValue());
	continueMessage();
}

void makePurchase()
{
	system("cls");
	cout << "Please enter the amount of money:" << endl;
	string input;
	double customerMoney = validatedDoubleParsing(input);
	if (customerMoney < total.getValue())
	{
		cout << "You are broke as fuck. Come again when you have atleast " << total.getValue() << "leva." << endl;
		continueMessage();
	}
	else
	{
		vector<Item> itemsForPurchase = total.getTtemsForPurchase();
		int length = itemsForPurchase.size();
		cout << "Items you purchased :" << endl;

		for (int i = 0; i < length; i++)
		{
			cout << "Item" << i + 1 << ":" << endl;
			cout << "Name: " << itemsForPurchase[i].getName() << endl;
			cout << "BIC: " << itemsForPurchase[i].getBIC() << endl;
			cout << "Value: " << itemsForPurchase[i].getValue() << endl;
		}

		cout << "Purchase information:" << endl;
		cout << "Address for delivery: " << customerAddress << endl;
		cout << "Purchases: ";
		printf("%.2fleva\n", total.getValue());
		cout << "Given: "; 
		printf("%.2fleva\n", customerMoney);
		cout << "Change: ";
		printf("%.2fleva\n", customerMoney - total.getValue());
		continueMessage();
	}

}

void continueMessage()
{
	cout << "Write 0 to continue" << endl;
	char input;
	cin >> input;
	while (input != '0')
	{
		cin >> input;
	}
	cin.ignore();
}


double validatedDoubleParsing(string input)
{
	double result;
	bool valid = false;
	while (!valid)
	{
		try
		{
			cout << "Please enter double number" << endl;
			cout << "Write the new value -> ";
			getline(cin, input);
			result = stod(input);
			valid = true;
			system("cls");
		}
		catch (invalid_argument ex)
		{
			valid = false;
		}
	}

	return result;
}