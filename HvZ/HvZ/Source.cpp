
//imports
#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <Windows.h>

#include "City.h"
#include "Human.h"
#include "Organism.h"
#include "Zombie.h"
using namespace std;

// Driver class

// Start conditions
int numberOfHumans = 0;
int numberOfZombies = 0;
int iterations = 0;

City *city = new City();
HANDLE  color = GetStdHandle(STD_OUTPUT_HANDLE);

void iteration(){
	// City, populate, move/methods, iterate
	city->move();
	numberOfHumans = city->numberOfHumans();
	numberOfZombies = city->numberOfZombies();
	iterations++;

	//Draw The city
	cout << *city;
	cout << endl;
	SetConsoleTextAttribute(color, 7); // Color option from Array in SPECS.H
	cout << "     Iterations: " << iterations;
	SetConsoleTextAttribute(color, HUMAN_COLOR);// Determined in SPECS.H
	cout << "  Humans: " << numberOfHumans;
	SetConsoleTextAttribute(color, ZOMBIE_COLOR);// Determined in SPECS.H
	cout << "  Zombies: " << numberOfZombies << "       " << endl;
	SetConsoleTextAttribute(color, BOARD_COLOR); // Determined in SPECS.H
	
	if (iterations == MAX_ITERATIONS) {
		if (numberOfHumans > numberOfZombies) {
			cout << "Humans win after 1000 iterations!";
		}
		else {
			cout << "Zombies win after 1000 iterations!";
		}
	}

}


int main(){
	// RNG
	srand(time(NULL)); // new rand seed

 //Populate the City with Humans
	do {
		int ranX = rand() % GRID_WIDTH; // starting x, y
		int ranY = rand() % GRID_HEIGHT;
		int randomSpawn = rand() % 4;

		if (city->getOrganism(ranX, ranY) == NULL) {
			//create and set human
			Human *myHuman = new Human(city, GRID_WIDTH, GRID_HEIGHT);
			myHuman->setPosition(ranX, ranY);
			myHuman->setSpawnCount(randomSpawn);
			city->setOrganism(myHuman, ranX, ranY);
			numberOfHumans++; // iterate human
		}

	} while (numberOfHumans < HUMAN_START_COUNT);

	//Populate the city with Zombies
	do {
		int ranX = rand() % GRID_WIDTH;
		int ranY = rand() % GRID_HEIGHT;
		int randomSpawn = rand() % 9;

		if (city->getOrganism(ranX, ranY) == NULL) {
			//create and set zombie
			Zombie *myZombie = new Zombie(city, GRID_WIDTH, GRID_HEIGHT);
			myZombie->setPosition(ranX, ranY);
			myZombie->setSpawnCount(randomSpawn);
			city->setOrganism(myZombie, ranX, ranY);
			numberOfZombies++; // iterate zombie
		}

	} while (numberOfZombies < ZOMBIE_START_COUNT);

	while (numberOfHumans > 0 && numberOfZombies > 0){ // loop while neither human or zombie population is 0, added iteration max
		if (iterations < MAX_ITERATIONS) // max iteration break  
			iteration();
	}

	//Output the Winner
	if (numberOfHumans > 0) {
		cout << "     Humans Win!"; 
	}
			else {
				cout << "     Zombies Win!"; 
			}

	_getch(); // hang
	return 0;
}
