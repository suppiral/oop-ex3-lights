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

/*	srand(12346);
	std::vector<GameNode> nodes;
	for (unsigned i = 0; i < 10; i++)
	{
		bool ant[6] = { bool(rand() % 2), bool(rand() % 2), bool(rand() % 2), bool(rand() % 2), bool(rand() % 2), bool(rand() % 2) };
		GameNode node(i, Point(float(40+80*i), float(80)), ant);
		nodes.push_back(node);
	}
	_board = new Graph<GameNode>(nodes);*/
}

// creates the window
void Controller::createWindow()
{
	// create window
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	_window.create(sf::VideoMode(WINDOW_W, WINDOW_H), "Aziz! Lights!", sf::Style::Default, settings);
	
	_window.setVerticalSyncEnabled(true); // set refresh rate as screen's refresh rate
	_window.setJoystickThreshold(10000); // joystick threshold
}

// read a level
void Controller::readLevel(std::ifstream &infd)
{
	std::vector <GameNode> nodes;
	bool antennot[NUM_OF_POSSIBLE_NEIGHBORS];
	Point point = INIT_POINT;;
	char c;
	unsigned num_of_rows;
	unsigned num_of_vtx;

	infd >> num_of_rows; // get the rows number

	// run on rows
	for( unsigned row = 0; row < num_of_rows; row++)
	{
		// if it is not the first vtx
		if( row > 0) {
			point.y += HEIGHT_DIFFRENCE;

			if ( row <= num_of_rows/2 )  // befor/ after the middle - the x location changes.
				point.x -= VERTEX_DISTANCE/2;
			else
				point.x += VERTEX_DISTANCE/2;
		}

		infd >> num_of_vtx; // get the number of vertices for this row.
		for ( unsigned i = 0; i < num_of_vtx; i++ )
		{
			if ( i > 0 ) // if it is not the first vertex in the row
				point.x += VERTEX_DISTANCE; // continue to the next vertex location (in row)
			
			while ( infd.peek() == space_c )  // go to the next vertex input 
				infd.get();

			for ( unsigned j = 0; j < NUM_OF_POSSIBLE_NEIGHBORS; j++) 
			{
				c = infd.get(); // get a no space char value

				switch (c)
				{
					// we should try to throw it in the middle in case of not a 0 or 1 value  //////
				case NoEdge:
					antennot[j] = false; // if its 1 "0"
					break;
				default:
					break;
				case Edge:  // if its a "1"
					antennot[j] = true;
					break;
				}
			}

			GameNode node(row*i, point, antennot);  // create a new Node
			nodes.push_back(node);
		}
	}
	_board = new Graph<GameNode>(nodes);
}

// run level game loop
bool Controller::runLevel()
{
	// =====================================================
	_light_source = 4;
	// =====================================================


	bool isCompleted = false;
	while (!isCompleted) 
	{
		draw();

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
	
	for (Graph<GameNode>::Iterator it = _board->begin(); !it.isEnd(); ++it)
		(*it).draw(_window);

	for (Graph<GameNode>::BFS_Iterator it(*_board, _light_source); !it.isEnd(); ++it)
		(*it).light(_window);

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
	{
		MOUSE_CLICK_TYPE click_type;
		// check which button was pressed
		switch (event.mouseButton.button)
		{
		case (sf::Mouse::Right):
			click_type = RIGHT;
			break;
		case (sf::Mouse::Left):
		default:
			click_type = LEFT;
			break;
		}

		for (Graph<GameNode>::Iterator it = _board->begin(); !it.isEnd(); ++it)
			if ((*it).click(*_board, Point(float(event.mouseButton.x), float(event.mouseButton.y)), click_type))
				break;
	}
		break;
	}
	return true;
}

// this function is creating the neighbors lists of all the nodes in the graph.
void Controller::createNeighborsLists()
{
	for ( Graph<GameNode>::Iterator it = _board->begin(); !it.isEnd(); ++it) 
	{
		Point point = (*it).getPos();
		for( int i = 0; i < NUM_OF_POSSIBLE_NEIGHBORS; i++ )
		{
			switch (i) {
			case FIRST_N:
				point.x -= VERTEX_DISTANCE;
				break;

			case SECOND_N:
				point.x -= EDGE_LENGTH;
				point.y -= VTX_HEIGHT_HEIGHT_DIFFRENCE;
				break;

			case THIRD_N:
				point.x += EDGE_LENGTH;
				point.y -= VTX_HEIGHT_HEIGHT_DIFFRENCE;
				break;

			case FOURTH_N:
				point.x += VERTEX_DISTANCE;
				break;

			case FIFTH_N:
				point.x += EDGE_LENGTH;
				point.y += VTX_HEIGHT_HEIGHT_DIFFRENCE;
				break;

			case SIXTH_N:
				point.x -=EDGE_LENGTH;
				point.y += VTX_HEIGHT_HEIGHT_DIFFRENCE;
				break;
			}

			// search the neighbor int the graph (if exists)
			(*it).setPotentialNeighbors ( i, search_neighbor(point) ) ; 
		}
	}

}


//this function gets a point of a potential neighbor of a node and look up for it in the graph
//it returns the index of the neighbor if found. otherwise it returns -1.
int Controller::search_neighbor(Point potential_neighbor)
{
	for ( Graph<GameNode>::Iterator it = _board->begin(); !it.isEnd(); ++it ) 
	{
		if ( (*it).getPos().x == potential_neighbor.x && (*it).getPos().y == potential_neighbor.y )
		if ( (*it).isPosIn(potential_neighbor))
			return it.get_index(); /// return the index  of the neighbor found on the graph
	}

	return NO_NEIGHBOR; // return the signal indicates that the potential neighbor is not found 
}
