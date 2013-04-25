#pragma once

#include <vector>
#include "Vertex.h"

template <class T>
class Graph {
public:
	Graph() { }							// default constructor
	
	void deter_neighbors_lists() // this function sets all vertexes neighbors lists at the beginning of the game.
	{
		for( unsigned i = 0; i < _vertices.size(); i++ )
			Point curr_vtx_loc = _vertices[i].get_loc();
			///.....
	}

	unsigned size() const { return _vertices.size(); }
	
	bool empty() const { return !_vertices.size(); }

	void push_back(const Point &location, T& value) 
	{
		Vertex<T> vertex(location, value);
		_vertices.push_back(vertex);
	}
	
private:
	std::vector<Vertex<T>> _vertices;
};