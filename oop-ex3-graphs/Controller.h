#pragma once

#include <SFML/Graphics.hpp>
#include "Graph.h"
#include "GameNode.h"

class Controller
{
public:
	Controller();
	~Controller();
	bool runLevel();

private:
	Graph<GameNode>* _board;
	sf::RenderWindow _window;

	void init();
	void readLevel();
	void createWindow();
	bool handleEvents(const sf::Event& event);

	void draw();
};