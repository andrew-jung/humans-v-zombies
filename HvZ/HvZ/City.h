
#ifndef CITY_H
#define CITY_H

// City header, partial from David Russell notes
#include <iostream>
#include <Windows.h>
#include "Specs.h"
using namespace std;

class Organism;

class City{
protected:
	Organism *grid[GRID_HEIGHT][GRID_WIDTH];

public:
	// Constructor 
	City();
	// Destructor
	virtual ~City();

	// Getters, setters
	Organism *getOrganism(int x, int y);
	void setOrganism(Organism *organism, int x, int y);

	// Methods
	void move();
	int numberOfHumans();
	int numberOfZombies();

	// Friend functions, override
	friend ostream& operator<<(ostream &output, City &city);
};

#endif