#pragma once

#include "Vertex.h"

template <class T>
class Graph {
	Graph();										// default constructor
	
	size_type size() const { return _vertices.size(); }
	
	bool empty() const { return !_vertices.size(); }


	void push_back(T& value) 
	{
		Vertex<T> vertex(value);
		_vertices.push_back(vertex);
	}
	
	private:
	std::vector<Vertex<T>> _vertices;
};