#include <iostream>

#include "game.h"

void drawProgramInfo()
{
	// Set color to magenta
	SET_FONT_COLOR(FONT_MAGENTA);
	printf("+================================================+\n");
	printf("\t    Air Defense System\n\n");
	printf("\t\t    Date\n");
	printf("\t\t  4/13/2019\n\n");
	printf("+================================================+\n");
	printf("\t\t Information\n");
	printf("+================================================+\n\n");
	printf("Description:\n");
	printf("\tThis project aims to simulate an AI-driven air-defense system of a randomly generated country.\n\n");
	printf("Tips:\n");
	printf("\t-At any point you can press 'esc' to quit!\n\n");
	printf("\t-Press 'R' to regenerate land\n");
	printf("\t-Press 'I' to retrieve information about the simulation\n");
	printf("\t-Press 'B' to initiate the projectile spawner\n");
	printf("\t-Press 'Left Mouse Button' to place a radar station\n");
	printf("\t-Press 'Right Mouse Button' to place a SAM site\n");
	printf("+================================================+\n");
	printf("\t\tBeginning Simulation\n");
	printf("+================================================+\n");
	printf(" \n");
	// Set color back to default
	SET_FONT_COLOR();
}

int main()
{
	drawProgramInfo();
	
	// Seed random for the program
	srand(std::time(0));

	Game game;
	
	game.begin();

	return 1;
}