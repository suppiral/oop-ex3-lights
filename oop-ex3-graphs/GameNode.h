// this is the header file for Game Node which holds the game relevant information of each vertex.

#pragma once

#include "Vertex.h"
#include "Graph.h"

class GameNode {
public:
	GameNode();

private:
	bool _edgesArray[NUM_OF_POSSIBLE_NEIGHBORS]; // this is the flag Array represents where the Node's edges.
	unsigned _potentialArray[NUM_OF_POSSIBLE_NEIGHBORS]; // this is the potential neighbers of the Node represented by their index on the graph. 
};

