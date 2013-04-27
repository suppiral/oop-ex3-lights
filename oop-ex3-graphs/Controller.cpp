#include "Controller.h"

// Constructor
Controller::Controller() : _board(NULL)
{
	init();
}
// Destructor
Controller::~Controller()
{
	delete _board;
}

// controller initialization
void Controller::init() 
{
	createWindow();
	readLevel();	
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
void Controller::readLevel()
{

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