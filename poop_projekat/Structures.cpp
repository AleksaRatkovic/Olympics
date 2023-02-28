#include "Structures.h"

void Structures::parseAthletes()
{
	ifstream file(pathAthlete);
	if (!file.is_open()) {
		cout << "File didn't open properly";
	}

	string line; //zovi stvari pravim imenom
	regex pattern("([^!]*)!([^!]*)!([A-Z])!([^!]*)!([^!]*)!.*");

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
				cout << endl << endl;
				
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

int Structures::countCompetitors()
{
	map<pair<string, int>, int> map;
	for_each(competitors.begin(), competitors.end(), [&map](const Competitor *c) {
		//Competitors who participate in more than one discipline on same Olympics we need to count just once
		if (c->getIndividual() == true) {
			map[pair<string, int>(c->getGames().getName(), c->getAthletes()[0])]++;
			}
		else {
			vector<int> ids = c->getAthletes();
			for (int i : ids) {
				map[pair<string, int>(c->getGames().getName(), i)]++;
			}
		}
		});

	return  map.size();
}
