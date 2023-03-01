#include "Structures.h"
#include "Athlete.h"
#include "Team.h"


int main() {
	Structures& s = Structures::getInstance("athletes.txt", "events.txt");

	s.parseAthletes();
	s.parseEvents();
	cout << s.countCompetitors();

	cout << endl << "\t" << s.averageHeight() << endl;

	cout << " \t" << s.averageWeight();
}