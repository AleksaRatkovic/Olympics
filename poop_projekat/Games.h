#pragma once

#include <iostream>

using namespace std;
class Games
{
	string og_name;
public:
	Games(string og): og_name(og) {}
	Games() {}

	string getName() const { return og_name; }

};

