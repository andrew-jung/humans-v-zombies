// Imports
#include "Zombie.h"
#include "Human.h"
using namespace std;

// Zombie class

// Constructor
Zombie::Zombie() {}
Zombie::Zombie(City *city, int width, int height) {
	this->city = city;
	this->width = width;
	this->height = height;
	this->starve = 0;
	srand(time(NULL));
}

// Destructor
Zombie::~Zombie() {}

// Getters, setters
void Zombie::setStarve(int eat) {
	this->starve = eat;
}

int Zombie::getStarve() {
	return this->starve;
}

// Inherited methods from Organism, override

void Zombie::move() {  // MOVE METHOD
	vector<int> moveDirections;
	// Check all directions (adj/diag)
	// use Organism/enums x, y coordinates/grid
	if (y - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x, y - 1)) != NULL) { moveDirections.push_back(NORTH); }
	if (y + 1 < height && dynamic_cast<Human*>(city->getOrganism(x, y + 1)) != NULL) { moveDirections.push_back(SOUTH); }
	if (x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y)) != NULL) { moveDirections.push_back(EAST); }
	if (x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y)) != NULL) { moveDirections.push_back(WEST); }
	if (y - 1 >= 0 && x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y - 1)) != NULL) { moveDirections.push_back(NORTH_EAST); }
	if (y + 1 < height && x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y + 1)) != NULL) { moveDirections.push_back(SOUTH_EAST); }
	if (y - 1 >= 0 && x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y - 1)) != NULL) { moveDirections.push_back(NORTH_WEST); }
	if (y + 1 < height && x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y + 1)) != NULL) { moveDirections.push_back(SOUTH_WEST); }
	
	// If no HUMAN, zombie move, else increment starve, move
	if (!moveDirections.empty())
		this->setStarve(0);
	else{
	// Zombie move, incr starve
		this->setStarve(this->getStarve() + 1); 
		// enum directions to move
		if (y - 1 >= 0 && city->getOrganism(x, y - 1) == NULL) { moveDirections.push_back(NORTH); }
		if (y + 1 < height && city->getOrganism(x, y + 1) == NULL) { moveDirections.push_back(SOUTH); }
		if (x + 1 < width && city->getOrganism(x + 1, y) == NULL) { moveDirections.push_back(EAST); }
		if (x - 1 >= 0 && city->getOrganism(x - 1, y) == NULL) { moveDirections.push_back(WEST); }
	}

	// as long as vector is not empty
	if (!moveDirections.empty()) {
		int move = moveDirections.at(rand() % moveDirections.size()); // random move by vector

		// Sets previous cell to NULL, the "move"
		city->setOrganism(NULL, x, y);

		//Sets the new position
		if (move == NORTH) { this->setPosition(x, y - 1); }
			else if (move == SOUTH) { this->setPosition(x, y + 1); }
			else if (move == EAST) { this->setPosition(x + 1, y); }
			else if (move == WEST) { this->setPosition(x - 1, y); }
			else if (move == NORTH_EAST) { this->setPosition(x + 1, y - 1); }
			else if (move == SOUTH_EAST) { this->setPosition(x + 1, y + 1); }
			else if (move == NORTH_WEST) { this->setPosition(x - 1, y - 1); }
			else if (move == SOUTH_WEST) { this->setPosition(x - 1, y + 1); }

		//adds the ZOMBIE to the CITY
		city->setOrganism(this, x, y);
	}
	this->setHasMoved(true); // bool value
	this->starveZombie(); //calls method to check if zombie has starved.
}

void Zombie::spawn() { // SPAWN METHOD

	if (this->getSpawnCount() >= ZOMBIE_BREED) { // zombie max count check
		vector<int> moveDirections; // dynamic directions
		srand(time(NULL)); // random timer

		 //Check for HUMAN (adj/diag) 
		if (y - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x, y - 1)) != NULL) { moveDirections.push_back(NORTH); }
		if (y + 1 < height && dynamic_cast<Human*>(city->getOrganism(x, y + 1)) != NULL) { moveDirections.push_back(SOUTH); }
		if (x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y)) != NULL) { moveDirections.push_back(EAST); }
		if (x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y)) != NULL) { moveDirections.push_back(WEST); }
		if (y - 1 >= 0 && x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y - 1)) != NULL) { moveDirections.push_back(NORTH_EAST); }
		if (y + 1 < height && x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y + 1)) != NULL) { moveDirections.push_back(SOUTH_EAST); }
		if (y - 1 >= 0 && x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y - 1)) != NULL) { moveDirections.push_back(NORTH_WEST); }
		if (y + 1 < height && x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y + 1)) != NULL) { moveDirections.push_back(SOUTH_WEST); }

		//Check if there are values in the vector
		if (!moveDirections.empty()){
			int spawnGridSpot = moveDirections.at(rand() % moveDirections.size()); //get random move from vector

			//create new zombie
			Zombie *myZombie = new Zombie(city, GRID_WIDTH, GRID_HEIGHT);

			//get zombie's new position by checking spawn
			if (spawnGridSpot == NORTH) { myZombie->setPosition(x, y - 1); }
				else if (spawnGridSpot == SOUTH) { myZombie->setPosition(x, y + 1); }
				else if (spawnGridSpot == EAST) { myZombie->setPosition(x + 1, y); }
				else if (spawnGridSpot == WEST) { myZombie->setPosition(x - 1, y); }
				else if (spawnGridSpot == NORTH_EAST) { myZombie->setPosition(x + 1, y - 1); }
				else if (spawnGridSpot == SOUTH_EAST) { myZombie->setPosition(x + 1, y + 1); }
				else if (spawnGridSpot == NORTH_WEST) { myZombie->setPosition(x - 1, y - 1); }
				else if (spawnGridSpot == SOUTH_WEST) { myZombie->setPosition(x - 1, y + 1); }

			city->setOrganism(myZombie, myZombie->x, myZombie->y); // call setter

			//set new zombie moved to true, change bools
			myZombie->setHasMoved(true);
			myZombie->setSpawnCount(0);
			myZombie->setHasSpawned(true);

			//reset if zombie has spawned
			this->setSpawnCount(0);
		}
	}else
		this->setSpawnCount(this->getSpawnCount() + 1); // increase the spawnCount
	}

// Zombie method
	void Zombie::starveZombie() { // if zombie has not "eaten" in ZOMBIE_STARVE (specs.h) turns, convert to human
		if (this->getStarve() >= ZOMBIE_STARVE) {
			Human *myHuman = new Human(city, GRID_WIDTH, GRID_HEIGHT); // create new human obj
			myHuman->setPosition(x, y); // place
			city->setOrganism(myHuman, x, y);
		}
	}