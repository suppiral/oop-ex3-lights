
#pragma once

#include <cmath>
#include <string>

// a point on the screen
struct Point {
	Point() { }
	Point(int x1, int y1) { x = x1; y = y1; }
	int x, y;
};

const unsigned NUM_OF_POSSIBLE_NEIGHBORS = 6;

const unsigned EDGE_LENGTH = 20; // the length of an edge.

const unsigned VERTEX_DISTANCE = 40; // this is the space between two vertexes.