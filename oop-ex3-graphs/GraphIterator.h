//this is the header file for the iterator of the graph

#pragma once

#include "Vertex.h"

template <class T>
class Graph; //  forward decleration



template <class T>
class GraphIterator {
public:
	GraphIterator(T& graph, unsigned ix);
	GraphIterator(GraphIterator<T>& other); //copy c-tor

	Vertex<T>& operator* ();

	GraphIterator<T> operator++()  //postfix
	{
		_index++;
		return (*this);    
	}          

	GraphIterator<T> operator++(int) //prefix 
	{
		GraphIterator copy(*this);
		_index++;
		return copy;
	}

	bool operator ==(GraphIterator& other); 

	bool operator !=(GraphIterator<T>& other);

	bool isEnd() const
	{
		return (_pointer == NULL);
	}

	T& operator [] (unsigned ix) { }



private:
	Graph<T>& _graph;
	unsigned int _index;
};
 

 ///// C-tor & D-tor /////
template <class T>
GraphIterator<T>::GraphIterator(T& graph, unsigned ix): _graph(graph), _index(ix)
{

}

template <class T>
Vertex<T>& GraphIterator<T>::operator * ()
{
	return (_graph._vertices[index]);
}

template <class T>
bool GraphIterator<T>::operator ==(GraphIterator<T>& other)
{
	return _index == other._index; 
}

template <class T>
bool GraphIterator<T>::operator !=(GraphIterator<T>& other)
{
	return _index != other._index; 
}
