#pragma once
#include "Sport.h"

class Event
{
	Sport sport;
	string city;
public:
	Event(Sport s, string n): sport(s), city(n) {}
	Event() {}

	Sport getSport() const { return sport; }
	string getCity() const { return city; }
};

