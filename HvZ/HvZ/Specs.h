#ifndef SPECS_H
#define SPECS_H

// Grid/game specs
const int GRID_HEIGHT = 20;
const int GRID_WIDTH = 20;
const double INTERVAL = .09; // time between steps (ms)
const int MAX_ITERATIONS = 1000;

// Human specs
const int HUMAN_START_COUNT = 100; // starting human count
const int HUMAN_BREED = 3; // 'steps' until Human breed occurs

// Zombie specs
const int ZOMBIE_START_COUNT = 5; // starting zombie count
const int ZOMBIE_BREED = 8; // 'steps' until Zombie breed occurs
const int ZOMBIE_STARVE = 3; // 'steps' until Zombie reverts by starving

// Color list/choices
const int HUMAN_COLOR = 13;
const int ZOMBIE_COLOR = 10;
const int BOARD_COLOR = 15;
//Colors
	//0  = black				//9  = bright blue
	//1  = blue					//10 = bright green
	//2  = green				//11 = bright turquoise
	//3  = turquise				//12 = bright red
	//4  = red					//13 = bright pink
	//5  = pink					//14 = bright yellow
	//6  = yellow				//15 = bright white
	//7  = white regular		//16+ = solid blocks
	//8  = white pale
#endif