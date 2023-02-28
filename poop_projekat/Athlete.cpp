#include "Athlete.h"

vector<int> Athlete::getAthletes() const
{
	vector<int> id;
	id.push_back(person->getID());
	return id;
}
