#pragma once
#include<iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Games.h"
#include "Medal.h"
#include "Event.h"
#include "Country.h"

using namespace std;

class Competitor
{
	Games games;
	Event event;
	Medal medal;
	Country country;
	bool individual;

public:
	Competitor(Games g, Event e, Medal m, Country c, bool i): games(g), event(e), medal(m), country(c), individual(i) {}
	Games getGames() const { return games; }
	Event getEvent() const { return event; }
	bool getIndividual() const { return individual; }
	Medal getMedal() const { return medal;  }
	Country getCountry() const { return country;  }

	virtual vector<int> getAthletes() const = 0;


};

