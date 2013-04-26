#pragma once

#include <vector>
#include "Vertex.h"

template <class T>
class Graph {
public:
	Graph() { }							// default constructor

	unsigned size() const { return _vertices.size(); }
	
	bool empty() const { return !_vertices.size(); }

	void push_back(T& value) 
	{
		Vertex<T> vertex(value);
		_vertices.push_back(vertex);
	}
	
private:
	std::vector<Vertex<T>> _vertices;
};