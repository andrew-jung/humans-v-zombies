#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <vector>
#include "Organism.h"
#include "City.h"
using namespace std;
// Zombie header, partial from David Russell notes

class Zombie : public Organism { // inherit Organism
protected:
	int starve; // Zombie only

public:
	// Constructor
	Zombie();
	Zombie(City *city, int width, int height);
	// Destructor
	virtual ~Zombie();

	// Inherited methods
	void move();
	void spawn();

	// Getters, setters
	int getStarve();
	void setStarve(int eat);

	// Methods
	void starveZombie();
};
#endif
