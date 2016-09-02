#include <iostream>
#include "Collector.h"
#include <algorithm>
#include "BrexitSystem.h"


using namespace std;

int main()
{
	shared_ptr<Collector> theCollector(new Collector("John", 45, Gender::Male, "London", "Englishman"));
	BrexitSystem::collectVoters(theCollector);
	BrexitSystem::collectorMenu(theCollector);

	system("pause");
	return 0;
}

