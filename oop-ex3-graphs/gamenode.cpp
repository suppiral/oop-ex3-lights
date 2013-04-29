#include "GameNode.h"

GameNode::GameNode(unsigned index, const Point &loc, bool antennot[]) : _my_index(index) // , _graphics(loc)
{ 
	for (unsigned i = 0; i < NUM_OF_POSSIBLE_NEIGHBORS; i++)
		_antennot[i] = antennot[i];
}