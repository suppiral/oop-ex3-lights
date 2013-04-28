#pragma once

#include <SFML/Graphics.hpp>
#include "Graph.h"
#include "GameNode.h"
#include <iostream>
#include <fstream>

class Controller
{
public:
	Controller(std::ifstream &infd);
	~Controller();
	bool runLevel();

private:
	Graph<GameNode>* _board;
	sf::RenderWindow _window;

	void init(std::ifstream &infd);
	void readLevel(std::ifstream &infd);
	void createWindow();
	bool handleEvents(const sf::Event& event);

	void draw();
};