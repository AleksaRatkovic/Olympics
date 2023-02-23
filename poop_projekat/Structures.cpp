#include "Structures.h"

void Structures::parseAthletes()
{
	ifstream file(pathAthlete);
	if (!file.is_open()) {
		cout << "Fajl nije otvoren kvalitetno";
	}

	string line; //zovi stvari pravim imenom
	regex pattern("([0-9])+!([^!]*)!([A-Z])!([^!]*)!([^!]*)!.*");

	while (getline(file, line)) {
		smatch result;
		if (regex_match(line, result, pattern)) {
			id = atoi(result.str(1).c_str());
			name = result.str(2);
			sex = result.str(3).at(0);
			age = atoi(result.str(4).c_str());
			height = result.str(5);
			weight = result.str(6);
		}

	}

	file.close();
	
}

void Structures::parseEvents()
{
	ifstream file(pathEvent);
	if (!file.is_open()) {
		cout << "Fajl nije otvoren kvalitetno";
	}

	string line; 
	regex pattern("([^!]*)!([^!]*)!([^!]*)!([^!]*)!([^!]*)!([^!]*)!([^!]*)!([^!]*).*");

	while (getline(file, line)) {
		smatch result;
		if (regex_match(line, result, pattern)) {
			oi = result.str(1);
			city = result.str(2);
			sport = result.str(3);
			discipline = result.str(4);
			competitorType = result.str(5);
			country = result.str(6);
			competitorID = result.str(7);
			medal = result.str(8);
		}
	}
	file.close();
}
