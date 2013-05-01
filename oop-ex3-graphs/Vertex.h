// Vertex class. container for values in Graph container.

#pragma once

#include <vector>

template <class T>
class Vertex {
public:
	Vertex(const T& node) : _node(node) { }	    // c-tor 
	
	bool addNeighbor(unsigned vertex) 
	{
		// check for duplicates
		for (unsigned i = 0; i < _neighbors.size(); i++)
			if (_neighbors[i] == vertex)
				return false;

		// if no duplicates: add
		_neighbors.push_back(vertex);
		return true;
	}

	bool remNeighbor(unsigned vertex) 
	{
		// search for neighbor
		for (unsigned i = 0; i < _neighbors.size(); i++)
		{
			// if found: erase
			if (_neighbors[i] == vertex)
			{
				_neighbors.erase(_neighbors.begin()+i);
				return true;
			}
		}

		return false;
	}

	T& getData() { return _node; }

private:
	T _node;
	std::vector<unsigned> _neighbors; // neighbors list.
};