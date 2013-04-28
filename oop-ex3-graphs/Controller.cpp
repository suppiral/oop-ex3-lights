#include "Controller.h"

// Constructor
Controller::Controller(std::ifstream &infd) : _board(NULL)
{
	init(infd);
}
// Destructor
Controller::~Controller()
{
	delete _board;
}

// controller initialization
void Controller::init(std::ifstream &infd) 
{
	createWindow();
	readLevel(infd);	
}

// creates the window
void Controller::createWindow()
{
	// create window
	_window.create(sf::VideoMode(WINDOW_W, WINDOW_H), "Aziz! Lights!");
	
	_window.setVerticalSyncEnabled(true); // set refresh rate as screen's refresh rate
	_window.setJoystickThreshold(10000); // joystick threshold
}

// read a level
void Controller::readLevel(std::ifstream &infd)
{
	std::vector < Vertex<GameNode> > vertices;
	bool edgesArray[NUM_OF_POSSIBLE_NEIGHBORS];
	Point point = INIT_POINT;
	char c;
	unsigned num_of_rows;
	unsigned num_of_vtx;

	while (infd.get() != Newline_c && !infd.eof());	// go to new line
	infd >> num_of_rows; // get the rows number

	for( unsigned row = 0; row < num_of_rows; row++)
	{
		if (point.y != INIT_POINT.y) //a new row of vertices
		{
			point.y += HEIGHT_DIFFRENCE;
			if ( row <= num_of_rows/2 )  // befor/ after the middle - the x location changes.
				point.x -= VERTEX_DISTANCE/2;
			else
				point.x += VERTEX_DISTANCE/2;
		}

		infd >> num_of_vtx; // get the number of vertices for this row.
		for ( unsigned i = 0; i < num_of_vtx; i++ )
		{
			if ( point.x != INIT_POINT.x )
			{
				point.x += VERTEX_DISTANCE; // continue to the next vertex location (in row)
			}
			while ( infd.peek() == space_c )  // go to the next vertex input 
				infd.get();

			for ( unsigned i = 0; i < NUM_OF_POSSIBLE_NEIGHBORS; i++) 
			{
				c = infd.get(); // get a no space char value

				switch (c)
				{
					// we should try to throw it in the middle in case of not a 0 or 1 value  //////
				case Edge:  // if its a "1"
					edgesArray[i] = EDGE_VAL;
					break;
				case NoEdge:
					edgesArray[i] = NO_EDGE_VAL; // if its 1 "0"
					break;
				}
			}

			GameNode node(point, edgesArray);  // create a new Node
			Vertex<GameNode>* vertex = new Vertex<GameNode>(node); // create a vertex out of it.
			//vertices.push_back(Vertex<GameNode>(node));
		}
	}
}


// run level game loop
bool Controller::runLevel()
{
	bool isCompleted = false;
	while (!isCompleted) 
	{
		_window.display();

		sf::Event event;
		_window.waitEvent(event);
		if (!handleEvents(event)) // check if X button pressed
			return false;

		// check condition for completation
		// isCompleted = ?

	}
	return true;
}

// draw game on screen
void Controller::draw()
{
	_window.clear();
	// <-- graph draw -->
	_window.display();
}

// handle game events
bool Controller::handleEvents(const sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::Closed:				// X button has been pressed:
		return false;					// indication to close the game
		break;

	case sf::Event::MouseButtonPressed: // Mouse Button pressed:
		// <-- graph check each node -->
		break;
	}
	return true;
}