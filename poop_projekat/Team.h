#pragma once


#include "Competitor.h"
#include"Person.h"
#include"Athlete.h"

class Team : public Competitor
{
	vector<Athlete*> athletes;
public:
	Team(Games g, Event e, Medal m, Country c, bool i, vector<Athlete*> a) : Competitor(g, e, m, c, i) {
		this->athletes = a;
	}

	virtual vector<int> getAthletes() const override;

};

