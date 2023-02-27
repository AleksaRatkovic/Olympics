#pragma once

#include<iostream>

using namespace std;
class Sport
{
	string name;
	string discipline;

public:
	Sport(string n, string d): name(n), discipline(d) {}
	Sport() {}

	string getName() const { return name; }
	string getDiscipline() const { return discipline; }
}; 

