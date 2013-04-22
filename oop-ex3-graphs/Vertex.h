#pragma once

template <class T>
class Vertex {
	Vertex(const T& value);
	Vertex(const Vertex& other);						// copy constructor
	Vertex& operator=(const Vertex& other);			// assignment operator
	
	addNeighbor(Vertex<T>* vertex) 
	{
		_neighbors.push_back(vertex);
	}
	remNeighbor(Vertex<T>* vertex) 
	{
		for (unsigned i = 0; i < _neighbors.size(); i++)
			// ........................
	}
	
	private:
		T& _value;
		std::vector<Vertex<T>*> _neighbors;
};