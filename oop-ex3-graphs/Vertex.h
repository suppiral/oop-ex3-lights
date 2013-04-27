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
		vertex->_neighbors.push_back(this);
	}
	void remNeighbor(Vertex<T>* vertex) 
	{
	//	for (unsigned i = 0; i < _neighbors.size(); i++)
			// ........................
	}

	Point get_loc() const; 
	T& get_val() { return _value; }

private:
	Point _location; // the location of the Node on the screen.
	T& _value; // the GameNode class will be the value that each vertex holds a Node in it. the Node has the specific information of it // GIL ?
	std::vector<Vertex<T>*> _neighbors; // this vector holds the real Vertex neighbors.
};


/// C-TOS AND D-TORS ///

template <class T>
Vertex<T>::Vertex(const Point &loc, const T& value): _value(value)
{
	
}