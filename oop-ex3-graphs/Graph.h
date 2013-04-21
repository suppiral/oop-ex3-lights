#pragma once

#include "Vertex.h"
#include "Edge.h"

template <class T>
class Graph {
	Graph();										// default constructor
	Graph(const Graph& other);						// copy constructor
	Graph& operator=(const Graph& other);			// assignment operator

	unsigned size() const;
	bool empty() const;


	void push_back(T& value);


};