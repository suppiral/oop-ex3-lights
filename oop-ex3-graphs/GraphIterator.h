//this is the header file for the iterator of the graph

#pragma once

#include "Graph.h"


template <class T>
class GraphIterator{
public:
	GraphIterator(T& graph);
	void next();
	bool isEnd() const{
		return (_pointer == NULL);
	}

	T& operator [] (unsigned ix){ }


private:
	Graph& _graph;
	Vertex<T>* _pointer;
};
