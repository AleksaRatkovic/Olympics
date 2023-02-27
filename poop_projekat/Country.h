#pragma once
#include<iostream>

using namespace std;

class Country
{
	string name;
public:
	Country(string n ) : name(n) {}
	Country() {}

	string getName() const { return name; }
};

