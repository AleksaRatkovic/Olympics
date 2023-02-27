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

	string getAthletes() const {
		string tmp;
		for ( Athlete* a : athletes) {
			tmp = tmp + a->getPerson().getName() + "\n";
		}

		return tmp;
	}

};

