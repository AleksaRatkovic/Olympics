#include "Team.h"

vector<int> Team::getAthletes() const
{
	vector<int> ids;
	for (Athlete* a : athletes) {
		ids.push_back(a->getPerson().getID());
	}

	return ids;
}
