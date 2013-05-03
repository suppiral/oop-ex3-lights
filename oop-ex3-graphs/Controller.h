#pragma once

#include <SFML/Graphics.hpp>
#include "Graph.h"
#include "GameNode.h"
#include "fstreams.h"

class Controller
{
public:
	Controller(ifstream &infd);
	~Controller();
	bool runLevel();

private:
	Graph<GameNode>* _board;
	sf::RenderWindow _window;
	unsigned _light_source;
	unsigned num_of_rows;

	void createWindow();
	void init(ifstream &infd);
	// --------------------------
	void createNeighborsLists();
	void readLevel(ifstream &infd);
	int search_neighbor(Point point);
	// --------------------------
	bool handleEvents(const sf::Event& event);
	

	void draw(Graph<GameNode>::BFS_Iterator& bfs_it);
};
