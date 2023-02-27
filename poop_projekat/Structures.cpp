#include "Structures.h"

void Structures::parseAthletes()
{
	ifstream file(pathAthlete);
	if (!file.is_open()) {
		cout << "File didn't open properly";
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

		Person* p = new Person(id, name, sex, age, height, weight);
		persons.push_back(p);

	}

	file.close();
	
}

void Structures::parseEvents()
{
	ifstream file(pathEvent);
	if (!file.is_open()) {
		cout << "File didn't open properly";
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

			Sport sp(sport, discipline);
			Event ev(sp, city);
			Games ga(oi);
			Country co(country);
			Medal me(medal);

			if (competitorType == "Individual") {
				int num = stoi(competitorID);
				Athlete* at = new Athlete(ga, ev, me, co, true, persons[num - 1]);
				competitors.push_back(at);
			}
			else {
				vector<int> nums = createTeam(competitorID);
				vector<Athlete*> athletes;
				for (int n : nums) {
					Athlete* at = new Athlete(ga, ev, me, co, true, persons[n - 1]);
					athletes.push_back(at);
				}
				Team* t = new Team(ga, ev, me, co, false, athletes);
				competitors.push_back(t);
			}

		}
	}
	file.close();
}

vector<int> Structures::createTeam(string s)
{
	vector<int> array;
	regex re("\\d+");

	sregex_iterator begin(s.begin(), s.end(), re);
	sregex_iterator end;

	while (begin != end) {
		smatch match = *begin;
		int n = stoi(match.str());
		array.push_back(n);
		begin++;
	}
	return array;
}
