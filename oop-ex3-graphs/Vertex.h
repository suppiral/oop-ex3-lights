// Vertex class. container for values in Graph container.

#pragma once

#include <vector>
#include "Macros.h"

template <class T>
class Vertex {
public:
	Vertex(T& value): _value(value) {}  // c-tor
	Vertex(const Vertex& other);					// copy constructor
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

private:
	T& _value;
	std::vector<Vertex<T>*> _neighbors; // neighbors list.
};