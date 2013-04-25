// Vertex class. container for values in Graph container.

#pragma once

#include <vector>

template <class T>
class Vertex {
public:
	Vertex(const T& value);
	Vertex(const Vertex& other);						// copy constructor
	Vertex& operator=(const Vertex& other);			// assignment operator
	
	void addNeighbor(Vertex<T>* vertex) 
	{
		_neighbors.push_back(vertex);
	}
	void remNeighbor(Vertex<T>* vertex) 
	{
	//	for (unsigned i = 0; i < _neighbors.size(); i++)
			// ........................
	}
	
private:
	T& _value;
	std::vector<Vertex<T>*> _neighbors;
};