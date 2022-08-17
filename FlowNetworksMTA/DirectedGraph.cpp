#include "DirectedGraph.h"

void DirectedGraph::makeEmptyGraph(int numberOfVertices)
{
	adjLists.resize(numberOfVertices);
}

std::list<int> DirectedGraph::getAdjList(int vertex)
{
	std::list<int> adjList;
	for (auto& edge : adjLists[vertex])
	{
		adjList.push_back(edge.getEnd());
	}
	adjList.sort();
	return adjList;
}

void DirectedGraph::addEdge(int startVertex, int endVertex, int cut)
{
	adjLists[startVertex].push_back(Edge(startVertex, endVertex, 0, cut));
}

void DirectedGraph::removeEdge(int startVertex, int endVertex)
{
	std::vector<Edge> adjList = adjLists[startVertex];
	adjList.erase(std::remove_if(adjList.begin(), adjList.end(), [&](Edge x) {return x.getEnd() == endVertex; }), adjList.end());
}