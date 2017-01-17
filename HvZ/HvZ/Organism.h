#ifndef ORGANISM_H
#define ORGANISM_H

// Organism header, partial from David Russell notes
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

class City;

class Organism{
protected: // accesible in inherited
	// Variables
	int x, y, height, width, spawnCount;
	bool hasMoved, hasSpawned;
	City *city;
	enum { WEST, NORTH, EAST, SOUTH, NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST };

public:
	// Constructor
	Organism();
	Organism(City *city, int width, int height);
	// Destructor
	virtual ~Organism();

	// virtual methods to override
	virtual void move() = 0;
	virtual void spawn() = 0;

	//Getters and Setters
	void setPosition(int x, int y);

	bool getHasMoved();
	void setHasMoved(bool hasMoved);

	bool getHasSpawned();
	void setHasSpawned(bool hasSpawned);

	int getSpawnCount();
	void setSpawnCount(int spawnCount);

	//friend functions & overrides
	friend ostream& operator<<(ostream &output, Organism *organism);

};//end class Organism
#endif
