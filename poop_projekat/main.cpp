#include "Structures.h"
#include "Athlete.h"
#include "Team.h"


int main() {
	Structures s("athletes.txt", "events.txt");

	s.parseAthletes();
	s.parseEvents();
	cout << s.countCompetitors();
}