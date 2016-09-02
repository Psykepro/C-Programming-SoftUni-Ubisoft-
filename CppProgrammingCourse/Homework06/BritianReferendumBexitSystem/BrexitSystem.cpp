#include "BrexitSystem.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

BrexitSystem::BrexitSystem()
{
}


BrexitSystem::~BrexitSystem()
{
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

map<string, int> generateResultsInNumbers(set<shared_ptr<Voter>> voters)
{
	map<string, int> results;
	results.insert(pair<string, int>("Leave", 0));
	results.insert(pair<string, int>("Stay", 0));
	for (set<shared_ptr<Voter>>::iterator it = voters.begin(); it != voters.end(); ++it)
	{
		string key = it->get()->getVote() == Vote::Stay ? "Stay" : "Leave";
		results[key]++;
	}

	return results;
}

void printResults(map<string, int> results, string messageBefore = "", string textAfterValues = "")
{
	if (messageBefore != "")
	{
		cout << messageBefore << endl;
	}

	for (map<string, int>::iterator it = results.begin(); it != results.end(); ++it)
	{
		string key = it->first;
		int value = it->second;
		cout << key + " : " << value << textAfterValues << endl;
	}
}

void printResults(map<string, double> results, string messageBefore = "", string textAfterValues = "")
{
	if (messageBefore != "")
	{
		cout << messageBefore << endl;
	}

	for (map<string, double>::iterator it = results.begin(); it != results.end(); ++it)
	{
		string key = it->first;
		double value = it->second;
		cout << key + " : " << value << textAfterValues << endl;
	}
}

void BrexitSystem::collectVoters(shared_ptr<Collector> theCollector)
{
	string input;

	cout << "Enter number of voters you want to add : " << endl;
	size_t numberOfVoters;
	cin >> numberOfVoters;

	for (int i = 0; i < numberOfVoters; i++)
	{
		system("cls");
		cout << "Voter " << i + 1 << endl;

		cout << "Enter name : ";
		string name;
		cin.ignore();
		getline(cin, name);

		cout << "Enter age : ";
		int age;
		cin >> age;

		cout << "Enter gender (Male / Female) : ";
		string gender;
		cin.ignore();
		getline(cin, gender);
		transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
		while (gender != "male" && gender != "female")
		{
			cout << "Valid gender types are -> Female and Male. Try again." << endl;
			getline(cin, gender);
			transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
		}
		Gender genderEnum = gender == "male" ? Gender::Male : Gender::Female;

		cout << "Enter living city/village : ";
		string livingPlace;
		getline(cin, livingPlace);

		cout << "Enter ethnos : ";
		string ethnos;
		getline(cin, ethnos);

		cout << "Enter vote (Stay / Leave) : ";
		string vote;
		getline(cin, vote);
		transform(vote.begin(), vote.end(), vote.begin(), ::tolower);
		while (vote != "stay" && vote != "leave")
		{
			cout << "Valid vote types are -> Stay and Leave. Try again." << endl;
			getline(cin, vote);
			transform(vote.begin(), vote.end(), vote.begin(), ::tolower);
		}
		Vote voteEnum = vote == "stay" ? Vote::Stay : Vote::Leave;

		theCollector->addVoter(make_shared<Voter>(name, age, genderEnum, livingPlace, ethnos, voteEnum));
	}
}

void BrexitSystem::generateAndPrintResultInPercent(set<shared_ptr<Voter>> voters)
{
	map<string, int> resultsInNumbers = generateResultsInNumbers(voters);
	int stayVotes = resultsInNumbers["Stay"];
	int leaveVotes = resultsInNumbers["Leave"];
	long allVotes = stayVotes + leaveVotes;
	double stayVotesInPercent = (stayVotes / (double)allVotes) * 100;
	double leaveVotesInPercent = (leaveVotes / (double)allVotes) * 100;
	map<string, double> resultsInPercent;
	resultsInPercent.insert(pair<string, double>("Stay", stayVotesInPercent));
	resultsInPercent.insert(pair<string, double>("Leave", leaveVotesInPercent));

	printResults(resultsInPercent, "<<< Results in percent >>>", "%");
}

void BrexitSystem::generateAndPrintResultInNumbers(set<shared_ptr<Voter>> voters)
{
	map<string, int> resultsInNumbers = generateResultsInNumbers(voters);
	printResults(resultsInNumbers, "<<< Results in numbers >>>");
}

void BrexitSystem::generateAndPrintResultOnAge(set<shared_ptr<Voter>> voters)
{
	cout << "<<< Results based on Age >>>" << endl;
	cout << "Possible ages : " << endl;
	set<int> possibleAges;
	for(set<shared_ptr<Voter>>::iterator it = voters.begin(); it != voters.end(); ++it)
	{
		int currentAge = it->get()->getAge();
		if(possibleAges.count(currentAge) == 0)
		{
			cout << currentAge << +", ";
		}
		possibleAges.insert(currentAge);
	}


	cout << endl << "Enter age : ";
	string choosenAge;
	getline(cin, choosenAge);

	bool isPossibleAge = possibleAges.find(stoi(choosenAge)) != possibleAges.end();
	while(!isPossibleAge)
	{
		cout << "Please enter possible age. Look above!" << endl;
		getline(cin, choosenAge);
		isPossibleAge = possibleAges.find(stoi(choosenAge)) != possibleAges.end();
	}
	set<shared_ptr<Voter>> filteredVoters;

	for (set<shared_ptr<Voter>>::iterator it = voters.begin(); it != voters.end(); ++it)
	{
		if(it->get()->getAge() == stoi(choosenAge))
		{
			filteredVoters.insert(*it);
		}
	}
	map<string, int> resultsInNumbers = generateResultsInNumbers(filteredVoters);
	system("cls");
	printResults(resultsInNumbers, "<<< Results in numbers, based on Age >>>");
}

void BrexitSystem::generateAndPrintResultOnEthnos(set<shared_ptr<Voter>> voters)
{
	cout << "<<< Results based on Ethnos >>>" << endl;
	cout << "Possible ethnoses : " << endl;
	set<string> possibleEthnoses;
	for (set<shared_ptr<Voter>>::iterator it = voters.begin(); it != voters.end(); ++it)
	{
		string currentEthnos = it->get()->getEthnos();
		if (possibleEthnoses.count(currentEthnos) == 0)
		{
			cout << currentEthnos << +", ";
		}
		possibleEthnoses.insert(currentEthnos);
	}


	cout << endl << "Enter ethnos : ";
	string choosenEthnos;
	getline(cin, choosenEthnos);

	bool isPossibleEthnos = possibleEthnoses.count(choosenEthnos) == 1;
	while (!isPossibleEthnos)
	{
		cout << "Please enter possible ethnos. Look above!" << endl;
		getline(cin, choosenEthnos);
		isPossibleEthnos = possibleEthnoses.count(choosenEthnos) == 1;
	}

	set<shared_ptr<Voter>> filteredVoters;

	for (set<shared_ptr<Voter>>::iterator it = voters.begin(); it != voters.end(); ++it)
	{
		if (it->get()->getEthnos() == choosenEthnos)
		{
			filteredVoters.insert(*it);
		}
	}
	map<string, int> resultsInNumbers = generateResultsInNumbers(filteredVoters);
	system("cls");
	printResults(resultsInNumbers, "<<< Results in numbers, based on Ethnos >>>");
}

void BrexitSystem::generateAndPrintResultOnLivingPlace(set<shared_ptr<Voter>> voters)
{
	cout << "<<< Results based on Living city/village >>>" << endl;
	cout << "Possible living city/village : " << endl;
	set<string> possibleLivingPlaces;
	for (set<shared_ptr<Voter>>::iterator it = voters.begin(); it != voters.end(); ++it)
	{
		string currentLivingPlace = it->get()->getLivingPlace();
		if (possibleLivingPlaces.count(currentLivingPlace) == 0)
		{
			cout << currentLivingPlace << +", ";
		}
		possibleLivingPlaces.insert(currentLivingPlace);
	}


	cout << endl << "Enter living city/village : ";
	string choosenLivingPlace;
	getline(cin, choosenLivingPlace);

	bool isPossibleLivingPlace = possibleLivingPlaces.count(choosenLivingPlace) == 1;
	while (!isPossibleLivingPlace)
	{
		cout << "Please enter possible living city/village. Look above!" << endl;
		getline(cin, choosenLivingPlace);
		isPossibleLivingPlace = possibleLivingPlaces.count(choosenLivingPlace) == 1;
	}

	set<shared_ptr<Voter>> filteredVoters;

	for (set<shared_ptr<Voter>>::iterator it = voters.begin(); it != voters.end(); ++it)
	{
		if (it->get()->getLivingPlace() == choosenLivingPlace)
		{
			filteredVoters.insert(*it);
		}
	}
	map<string, int> resultsInNumbers = generateResultsInNumbers(filteredVoters);
	system("cls");
	printResults(resultsInNumbers, "<<< Results in numbers, based on Living city/village >>>");
}

void BrexitSystem::collectorMenu(shared_ptr<Collector> theCollector)
{
	string input;
	bool collectorsMode = false;
	while (input != "Quit")
	{
		system("cls");
		cout << "If you want to quit just write - Quit" << endl;

		if (!collectorsMode)
		{
			cout << "Enter the special password to enter the collector's menu!" << endl;
			getline(cin, input);
			if (input == "12344321")
			{
				collectorsMode = true;
			}
		}
		else
		{
			cout << ">>> You entered the collector's menu <<<" << endl;
			cout << "Enter the number infront the function which you wanna run:" << endl;
			cout << "1.Result in percent" << endl;
			cout << "2.Result in numbers" << endl;
			cout << "3.Result based on Age" << endl;
			cout << "4.Result based on Ethnos" << endl;
			cout << "5.Result based on Living city/village" << endl;
			getline(cin, input);
			set<shared_ptr<Voter>> voters = theCollector->getVoters();
			switch (input[0])
			{
			case '1':
				system("cls");
				generateAndPrintResultInPercent(voters);
				continueMessage();
				break;
			case '2':
				system("cls");
				generateAndPrintResultInNumbers(voters);
				continueMessage();
				break;
			case '3':
				system("cls");
				generateAndPrintResultOnAge(voters);
				continueMessage();
				break;
			case '4':
				system("cls");
				generateAndPrintResultOnEthnos(voters);
				continueMessage();
				break;
			case '5':
				system("cls");
				generateAndPrintResultOnLivingPlace(voters);
				continueMessage();
				break;
			}
		}
	}
}

