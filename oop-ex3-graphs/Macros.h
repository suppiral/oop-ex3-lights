#pragma once

#include <cmath>

// a point on the screen
struct Point {
	Point() { }
	Point(double x1, double y1) { x = x1; y = y1; }
	double x, y;
};

const unsigned WINDOW_W = 800;
const unsigned WINDOW_H = 600;


const unsigned NUM_OF_POSSIBLE_NEIGHBORS = 6;
const unsigned EDGE_LENGTH = 20; // the length of an edge.
const unsigned VERTEX_DISTANCE = 40; // this is the space between two vertexes.
const double HEIGHT_DIFFRENCE = (sqrt(3.0)/2)*EDGE_LENGTH; // the height diffrence between two rows is e.q triangle height.
const unsigned FIRST_ROW_VTX_NUM = 3;

const char Edge = '0' ;
const char NoEdge = '1' ;
const char space_c = ' ';
const char Newline_c = '\n';

const unsigned EDGE_VAL = 1;
const unsigned NO_EDGE_VAL = 0;

const Point INIT_POINT(250,250);  // the first on the screen
