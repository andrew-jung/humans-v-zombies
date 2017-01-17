// Imports
#include "Organism.h"
#include "Human.h"
#include "Zombie.h"
using namespace std;

// Organism class

// Default constructor
Organism:: Organism(){}

// Constructor
Organism::Organism(City *city, int width, int height) {
	this->city = city;
	this->width = width;
	this->height = height;
}

// Destructor
Organism::~Organism() {}

// Getters, setters
void Organism::setPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

void Organism::setHasMoved(bool hasMoved) {
	this->hasMoved = hasMoved;
}

bool Organism::getHasMoved(){ 
	return this->hasMoved; 
}

void Organism::setHasSpawned(bool hasSpawned){ 
	this->hasSpawned = hasSpawned; 
}

bool Organism::getHasSpawned(){
	return this->hasSpawned; 
}

void Organism::setSpawnCount(int spawnCount){
	this->spawnCount = spawnCount; 
} 

int Organism::getSpawnCount(){
	return this->spawnCount; 
}
// end getters, setters

// Friend functions/overload
ostream& operator<<(ostream &output, Organism *organism) {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); // change color in output
	// Check human [O] or zombie [X], and prints to console accordingly.
	//Depending on Human or Zombie, will ouput 'O' or 'X', respectfully
	if (dynamic_cast<Human*>(organism) != NULL){ //Human
		SetConsoleTextAttribute(color, HUMAN_COLOR);
		output << "O";
		SetConsoleTextAttribute(color, BOARD_COLOR);
	}
	else if (dynamic_cast<Zombie*>(organism) != NULL){ //Zombie
		SetConsoleTextAttribute(color, ZOMBIE_COLOR);
		output << "X";
		SetConsoleTextAttribute(color, BOARD_COLOR);
	}
	else //Empty space on grid
		output << " ";

	return output;
}