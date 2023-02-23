#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include <regex>
#include <vector>
#include"Competitor.h"

using namespace std;


class Structures
{
	string pathAthlete, pathEvent;
	vector<Competitor*> array;
	// fields for athlete
	int id;
	string name;
	char sex;
	int age;
	string height;
	string weight;

	//fields for event
	string oi;
	string city;
	string sport;
	string discipline;
	string competitorType;
	string country;
	string competitorID;
	string medal;

public:
	Structures(string a, string e) : pathAthlete(a), pathEvent(e) {}

	void parseAthletes();
	void parseEvents();




	

};

