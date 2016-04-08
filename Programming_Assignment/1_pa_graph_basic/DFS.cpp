// CSE 101 Winter 2016, PA 1
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: 1/22/2016 at 11:59 PM

#ifndef __DFS_CPP__
#define __DFS_CPP__

#include "Graph.hpp"
#include <set>
// include more libraries as needed


template <class T>
void dfs_local(Graph<T>& g, Vertex<T> *u, std::set<T>& visited)
{
	for(typename std::list<T>::iterator itr=u->edges.begin(); itr != u->edges.end(); itr++)
	{
		if(g.vertices[*itr]->visited == false)
		{
			g.vertices[*itr]->visited = true;
			visited.insert(*itr);
			dfs_local(g, g.vertices[*itr],visited);
		}
	}
}


template <class T>
std::set<T> dfs(Graph<T>& g, T t)
{
    std::set<T> visited;
	g.vertices[t]->visited = true;
	dfs_local(g, g.vertices[t], visited);
	return visited;
}


#endif
