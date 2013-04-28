// this is the header file for Game Node which holds the game relevant information of each vertex.

#pragma once
#include "Macros.h"

class GameNode {
public:
	GameNode(const Point &loc, bool edgesArray[]);
	bool click();


private:
	Point _location;
	bool _edgesArray[NUM_OF_POSSIBLE_NEIGHBORS]; // this is the flag Array represents where the Node's edges.
	unsigned _potentialArray[NUM_OF_POSSIBLE_NEIGHBORS]; // potential neighbors of the Node represented by their index on the graph.


	//GameNodeGraphics _graphics; // graphic representation of the Game node.
};
