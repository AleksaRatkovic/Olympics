#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include <regex>
#include <vector>
#include <array>
#include"Person.h"
#include"Competitor.h"
#include"Athlete.h"
#include"Team.h"



using namespace std;


class Structures
{
	string pathAthlete, pathEvent;
	vector<Person*> persons;
	vector<Competitor*> competitors;
	//svector<Competitor*> competitors;
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
	vector<int> createTeam(string s);
	//void createCompetitor();




	

};

