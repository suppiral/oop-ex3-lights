// source code for GameNodeGraphics.
// contains the graphical representation of a node in the game.


#include "GameNodeGraphics.h"

#define GRAY sf::Color::Color(125,125,125)

// Constructor: gets points on screen
GameNodeGraphics::GameNodeGraphics(const Point& loc) : _lightbulb(float(NODE_RADIUS))
{
	// setup lightbulb
	_lightbulb.setFillColor(GRAY);
	_lightbulb.setOrigin(float(NODE_RADIUS), float(NODE_RADIUS));
	_lightbulb.setPosition(float(loc.x), float(loc.y));

	// -----------------------------------------------
	// setup antennot
	for (unsigned i = 0; i < NUM_OF_POSSIBLE_NEIGHBORS; i++)
	{
		// antennot are lines constructed by sf::RectangleShape and rotated around the source: the light bulb
		sf::RectangleShape line;
		line.setSize((sf::Vector2f(float(EDGE_LENGTH), float(ANTENNA_WIDTH))));
		line.setPosition(float(loc.x), float(loc.y));
		line.setOrigin(0.f, float(ANTENNA_WIDTH)/2);

		line.rotate(-(float(360/NUM_OF_POSSIBLE_NEIGHBORS)*i));
		_antennot.push_back(line);
	}
}

// check if position is on lightbulb
bool GameNodeGraphics::isPosIn(const Point& pos) const
{
	// get bounds of node
	sf::FloatRect bounds = _lightbulb.getGlobalBounds();
	// don't forget the edges
	bounds.left -= EDGE_LENGTH/2;
	bounds.top -= EDGE_LENGTH/2;
	bounds.width += EDGE_LENGTH;
	bounds.height += EDGE_LENGTH;

	// return if contains pos
	return bounds.contains(float(pos.x), float(pos.y));
}


// Drawing: gets window to draw on and which antennot to draw
void GameNodeGraphics::draw(sf::RenderWindow& window, bool antennot_logic[NUM_OF_POSSIBLE_NEIGHBORS]) 
{
	// draw antenna if there's one according to antennot logic
	for (unsigned i = 0; i < NUM_OF_POSSIBLE_NEIGHBORS; i++)
		if (antennot_logic[i])
			window.draw(_antennot[i]);
	
	// draw a gray lightbulb
	_lightbulb.setFillColor(GRAY);
	window.draw(_lightbulb);
}
void GameNodeGraphics::light(sf::RenderWindow& window)
{
	// draw a yellow lightbulb
	_lightbulb.setFillColor(sf::Color::Yellow);
	window.draw(_lightbulb);
}

Point GameNodeGraphics::getPos() const
{
	return Point(float(_lightbulb.getPosition().x), float(_lightbulb.getPosition().y));
}