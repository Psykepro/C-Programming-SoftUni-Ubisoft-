#pragma once
#include <set>
#include <memory>
#include "Voter.h"
#include "Collector.h"

class BrexitSystem
{
public:
	BrexitSystem();
	~BrexitSystem();
	static void collectVoters(shared_ptr<Collector> theCollector);
	static void collectorMenu(shared_ptr<Collector> theCollector);
	static void generateAndPrintResultInPercent(set<shared_ptr<Voter>> voters);
	static void generateAndPrintResultInNumbers(set<shared_ptr<Voter>> voters);
	static void generateAndPrintResultOnAge(set<shared_ptr<Voter>> voters);
	static void generateAndPrintResultOnEthnos(set<shared_ptr<Voter>> voters);
	static void generateAndPrintResultOnLivingPlace(set<shared_ptr<Voter>> voters);	
};

