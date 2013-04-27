#pragma once

#include <vector>
#include "Vertex.h"

template <class T>
class Graph {
public:
	// constructors
	Graph() { }							// default constructor
	Graph(std::vector<Vertex<T>>& vertices) : _vertices(vertices) { }

	// information
	unsigned size() const { return _vertices.size(); }
	bool empty() const { return !_vertices.size(); }

	// operations
	void push_back(T& value) 
	{
		Vertex<T> vertex(value);
		_vertices.push_back(vertex);
	}

	bool addEdge(unsigned i, unsigned j) {
		if (!(i < size() && j < size()))
			return false;

		if (_vertices[i].addEdge(j))
			return _vertices[j].addEdge(i);

		return false;
	}
	bool remEdge(unsigned i, unsigned j) {
		if (!(i < size() && j < size()))
			return false;

		if (_vertices[i].remEdge(j))
			return _vertices[j].remEdge(i);

		return false;
	}

	//GraphIterator begin();
	//GraphIterator end();

	
private:
	std::vector<Vertex<T>> _vertices;
};