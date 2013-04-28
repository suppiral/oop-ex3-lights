/// this is the cpp file for the GameNode class

#include "GameNode.h"

GameNode::GameNode(const Point &loc, bool edgesArray[]): _location(loc)
{
	for ( int i = 0; i < NUM_OF_POSSIBLE_NEIGHBORS; i++)
		_edgesArray[i] = edgesArray[i];	
}