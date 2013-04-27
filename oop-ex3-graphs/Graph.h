#pragma once

#include <vector>
#include "Vertex.h"

template <class T>
class Graph {
public:
	// constructors
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
	
	class GraphIterator;
	//friend class GraphIterator;

	GraphIterator begin() { return GraphIterator<T>(*this, i); }
	GraphIterator end() { return GraphIterator(*this, _vertices.size()) ; }

	
private:
	std::vector<Vertex<T>> _vertices;
};



template <class T>
class Graph<T>::GraphIterator {
public:
	GraphIterator(Graph<T>& graph, unsigned i) : _graph(graph), _index(i) { }
//	GraphIterator(GraphIterator<T>& other); //copy c-tor

	Vertex<T>& operator* () { return (_graph._vertices[index]); }

	GraphIterator operator++() //postfix
	{
		_index++;
		return (*this);
	}

	GraphIterator operator++(int) //prefix
	{
		GraphIterator copy(*this);
		_index++;
		return copy;
	}

	bool operator ==(GraphIterator& other)
	{
		if (&_graph != &other._graph)
			return false;
		return _index == other._index;
	}

	bool operator !=(GraphIterator& other)
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