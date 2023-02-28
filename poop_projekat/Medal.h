#pragma once

#include<iostream>

using namespace std;
class Medal
{
	string name;

public:
	Medal(string m): name(m) {}
	Medal() {}

	string getMedal() const { return name; }
};

