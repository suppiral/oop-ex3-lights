// Vertex class. container for values in Graph container.

#pragma once

#include <vector>
#include "Macros.h"


template <class T>
class Vertex {
public:
	Vertex(const T& node) : _node(node) { }			// c-tor 
	
	void addNeighbor(unsigned vertex) 
	{
		_neighbors.push_back(vertex);
	}
	void remNeighbor(unsigned vertex) 
	{
	//	for (unsigned i = 0; i < _neighbors.size(); i++)
			// ........................
	}

	T& getNode() { return _node; }

private:
	T _node;
	std::vector<unsigned> _neighbors; // neighbors list.
};