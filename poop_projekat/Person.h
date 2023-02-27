#pragma once
#include<iostream>

using namespace std;
class Person
{

	int id;
	string name;
	int age;
	char sex;
	string height;
	string weight;
public:
	Person() = default;
	Person(int i, string n, int a, char s, string h, string w) {
		this->id = i;
		this->name = n;
		this->age = a;
		this->sex = s;
		this->height = h;
		this->weight = w;

	}

	int getID() const { return this->id; }
	int getAge() const { return this->age; }
	char getSex() const { return this->sex; }
	string getName() const { return this->name; }
	string getWeight() const { return this->weight; }
	string getHeight() const { return this->height; }

};

