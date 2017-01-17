#ifndef HUMAN_H
#define HUMAN_H
// Human header, partial from David Russell notes

#include <vector>
#include "Organism.h"
#include "City.h"
using namespace std;

class Human : public Organism { // inherit Organism
public:
	// Constructor
	Human();
	Human(City *city, int width, int height);
	// Destructor
	virtual ~Human();

	// Inherited methods
	void move();
	void spawn();
};

#endif
