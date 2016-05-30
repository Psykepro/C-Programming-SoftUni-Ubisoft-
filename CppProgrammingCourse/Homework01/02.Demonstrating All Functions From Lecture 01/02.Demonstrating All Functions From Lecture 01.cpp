// 02.Demonstrating All Functions From Lecture 01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Hello" << endl;

	// long long == 2x(long) size
	long long size = 2;
	float floatNum = 3.141592141592f;
	cout << floatNum << endl;
	// long double == 2x(double) size
	long double longDoubleNum = 3.141592141592;
	double doubleNum = 3.141592141592;

	char array[] = "value01 value02";
	for (int i = 0; i < sizeof(array); i++)
	{
		cout << array[i] << endl;
	}

	// Function cin automatically split strings by : /t /n /s.
	// If we don't use getline(cin, input); from library <strings>.
	string input;
	getline(cin, input);


	return 0;
}

int 

