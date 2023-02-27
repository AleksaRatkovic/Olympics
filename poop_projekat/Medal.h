#pragma once

#include<iostream>

using namespace std;
class Medal
{
	string medal;

public:
	Medal(string m): medal(m) {}
	Medal() {}

	string getMedal() const { return medal; }
};

