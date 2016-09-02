// 01.ASCII Table Character Indentifier.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Arrange
	string line;
	int upperCaseCounter = 0;
	int lowerCaseCounter = 0;
	int otherCharCounter = 0;
	cout << "Enter some string: " << endl;
	getline(cin, line);

	// Act
	for (int i = 0; i < line.size(); i++) {
		if (int(line[i]) >= 65 && int(line[i]) <= 90) 
		{
			// upperCase
			upperCaseCounter++;
		}
		else if (int(line[i]) >= 97 && int(line[i]) <= 122) 
		{
			// lowerCase
			lowerCaseCounter++;
		}
		else
		{
			// otherChar
			otherCharCounter++;
		}
	}

	// Assert
	cout << "Upper Case Characters:" << endl << upperCaseCounter << endl;
	cout << "Lower Case Characters:" << endl << lowerCaseCounter << endl;
	cout << "Other Characters:" << endl << otherCharCounter << endl;

    return 0;
}

