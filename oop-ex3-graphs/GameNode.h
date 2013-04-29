// this is the header file for Game Node which holds the game relevant information of each vertex.

#pragma once

#include "Graph.h"


class GameNode {
public:
	GameNode(unsigned index, const Point &loc, bool antennot[]);
	void addPotential(unsigned neigh);
	bool click(Graph<GameNode>& graph);


private:
	unsigned _my_index;
	bool _antennot[NUM_OF_POSSIBLE_NEIGHBORS]; // this is the flag Array represents where the Node's edges.
	unsigned _potentialNeighbors[NUM_OF_POSSIBLE_NEIGHBORS]; // potential neighbors of the Node represented by their index on the graph.


	//GameNodeGraphics _graphics; // graphic representation of the Game node.
};

