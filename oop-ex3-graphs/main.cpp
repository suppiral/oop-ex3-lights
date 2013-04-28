#include "Controller.h"
#include "fstreams.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <fstream>

int main()
{
	int num_of_levels = 0;
	bool completed = true; // has the player completed the level?
	ifstream infd; // in file stream
	fstreams::OpenFile(infd, "board.txt"); // oepn board

	infd >> num_of_levels; // get num of levels

	for ( int level = 0; level < num_of_levels && completed && !infd.eof()  ; level++)
	{
		Controller ctrl(infd);
	
	}

	Controller ctrl(infd);
	ctrl.runLevel();

	return EXIT_SUCCESS;
}