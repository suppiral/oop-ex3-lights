// source code for GameNode class.
// a game node contains the logic of the game.

#include "GameNode.h"

const unsigned TO_OPPOSITE = 3;


// Constructor
// get: index in graph, location on screen and antennot
GameNode::GameNode(unsigned index, const Point &loc, bool antennot[]) : _my_index(index), _graphics(loc)
{ 
	// init antennot
	for (unsigned i = 0; i < NUM_OF_POSSIBLE_NEIGHBORS; i++)
		_antennot[i] = antennot[i];
}

// check if opposite antenna exists at gameNode index
bool GameNode::checkAntenna(unsigned index) const
{
	// validate
	if (index >= NUM_OF_POSSIBLE_NEIGHBORS)
		return false;

	// return opposite antenna status (clock rotation)
	return _antennot[(index+TO_OPPOSITE) % NUM_OF_POSSIBLE_NEIGHBORS];
}

// event handler for clicking on the game node
bool GameNode::click(Graph<GameNode>& graph, Point& loc, MOUSE_CLICK_TYPE click)
{
	// check location
	if (!_graphics.isPosIn(loc))
			return false;

	bool last_antennot[NUM_OF_POSSIBLE_NEIGHBORS];
	// shift antennot right or left and remember last position of them
	if (click == RIGHT)
		shiftRight(last_antennot);
	else shiftLeft(last_antennot);

	// add/remove edges in graph
	for (unsigned i = 0; i < NUM_OF_POSSIBLE_NEIGHBORS; i++)
	{
		// rem lost edges
		if (_potentialNeighbors[i] > NO_NEIGHBOR && _antennot[i] == false &&
						graph[_potentialNeighbors[i]].checkAntenna(i))
			graph.remEdge(_my_index, _potentialNeighbors[i]);
		// add new adges
		else if (_potentialNeighbors[i] > NO_NEIGHBOR && _antennot[i] == true &&
						graph[_potentialNeighbors[i]].checkAntenna(i))
			graph.addEdge(_my_index, _potentialNeighbors[i]); 
	}
	return true;
}

// shift antennot left
void GameNode::shiftLeft(bool last_antennot[]) { shift(last_antennot, NUM_OF_POSSIBLE_NEIGHBORS-1); }
// shift antennot right
void GameNode::shiftRight(bool last_antennot[]) { shift(last_antennot, 1); }

// shift antennot according to shifter
void GameNode::shift(bool last_antennot[], unsigned shifter)
{
	// save 
	for (unsigned i = 0; i < NUM_OF_POSSIBLE_NEIGHBORS; i++)
		last_antennot[i] = _antennot[i];

	// shift
	for (unsigned i = 0; i < NUM_OF_POSSIBLE_NEIGHBORS; i++)
		_antennot[i] = last_antennot[(i+shifter) % NUM_OF_POSSIBLE_NEIGHBORS];
}

// draw
void GameNode::draw(sf::RenderWindow& window)
{
	_graphics.draw(window, _antennot);
}
// draw light
void GameNode::light(sf::RenderWindow& window)
{
	_graphics.light(window);
}

// set potenial neighbor at index
void GameNode::setPotentialNeighbors(int index, int neighbor)
{
	_potentialNeighbors[index] = neighbor;
}