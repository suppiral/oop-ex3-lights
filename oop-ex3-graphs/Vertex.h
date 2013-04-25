// Vertex class. container for values in Graph container.

#pragma once

#include <vector>
#include "Macros.h"

template <class T>
class Vertex {
public:
	Vertex(const Point &loc, const T& value);           // c-tor 
	Vertex(const Vertex& other);						// copy constructor
	Vertex& operator=(const Vertex& other);			// assignment operator
	
	void addNeighbor(Vertex<T>* vertex) 
	{
		_neighbors.push_back(vertex);
	}
	void remNeighbor(Vertex<T>* vertex) 
	{
	//	for (unsigned i = 0; i < _neighbors.size(); i++)
			// ........................
	}

	Point get_loc() const; 

private:
	Point _location; // the location of the Node on the screen.
	//GameNode _node;  // each vertex holds a Node in it. the Node has the specific information of it. 
	T& _value;
	std::vector<Vertex<T>*> _neighbors; // this vector holds the real Vertex neighbors.
};