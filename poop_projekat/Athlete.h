#pragma once
#include"Competitor.h"
#include"Person.h"

class Athlete : public Competitor
{

	Person* person;
public:
	Athlete(Games g, Event e, Medal m, Country c, bool i, Person* p) : Competitor(g, e, m, c, i) {
		this->person = p;
	}

	Person getPerson() const { return *person; }

	virtual vector<int> getAthletes() const override;
		
	


};

