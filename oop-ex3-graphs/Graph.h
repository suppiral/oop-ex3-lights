/* 
* Graph container class.
*/

#pragma once

#include <vector>
#include "Vertex.h"

template <class T>
class Graph {
public:
	// constructors
	Graph(std::vector<T>& nodes)
	{
		for (unsigned i = 0; i < nodes.size(); i++)
		{
			Vertex<T> vertex(nodes[i]);
			_vertices.push_back(vertex);
		}
	}

	// information
	unsigned size() const { return _vertices.size(); }
	bool empty() const { return !_vertices.size(); }

	// operations
	bool addEdge(unsigned i, unsigned j) 
	{
		// check validity of parameters
		if (!(i < size() && j < size()))
			return false;

		// add edges
		if (_vertices[i].addNeighbor(j))
			return _vertices[j].addNeighbor(i);

		return false;
	}

	bool remEdge(unsigned i, unsigned j) 
	{
		// check validity of parameters
		if (!(i < size() && j < size()))
			return false;

		// remove edges
		if (_vertices[i].remNeighbor(j))
			return _vertices[j].remNeighbor(i);

		return false;
	}
	
	class Iterator;
	friend class Iterator;

	Iterator begin() { return Iterator<T>(*this, i); }
	Iterator end() { return Iterator(*this, _vertices.size()) ; }

	
private:
	std::vector<Vertex<T>> _vertices;
};



template <class T>
class Graph<T>::Iterator {
public:
	Iterator(Graph<T>& graph, unsigned i) : _graph(graph), _index(i) { }
	Iterator(Iterator& other); //copy c-tor  >> not implemented <<

	T& operator* () { return _graph._vertices[index].getNode(); }

	Iterator operator++() //prefix
	{
		++_index;
		return (*this);
	}

	Iterator operator++(int) //postfix
	{
		Iterator copy(*this);
		++_index;
		return copy;
	}

	bool operator ==(Iterator& other)
	{
		if (&_graph != &(other._graph))
			return false;
		return _index == other._index;
	}

	bool operator !=(Iterator& other)
	{
		return !(*this == other);
	}

	bool isEnd() const
	{
		return _index >= _graph.size();
	}

private:
	Graph<T>& _graph;
	unsigned int _index;
};