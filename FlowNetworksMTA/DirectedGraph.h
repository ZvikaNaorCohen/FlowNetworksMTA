#pragma once
#include <vector>
#include <list>
#include "Edge.h"

using namespace std;

class DirectedGraph
{
	std::vector<std::vector<Edge>> adjLists;


public:
	void makeEmptyGraph(int numberOfVertices);
	std::list<int> getAdjList(int i_Vertex);
	void addEdge(int startVertex, int endVertex, int cut);
	void removeEdge(int startVertex, int endVertex);
	void runBFS(int s, vector<int>& d, vector<int>& p);
};

