#include "DirectedGraph.h"

#include <queue>

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

void DirectedGraph::runBFS(int s, vector<int>& d, vector<int>& p)
{
	queue<int> Q;
	int numberOfVertices = adjLists.size();
	d.resize(numberOfVertices);
	p.resize(numberOfVertices);
	for (int i = 0; i < numberOfVertices; i++)
	{
		d[i] = INT32_MAX;
		p[i] = NULL;
	}

	Q.push(s);
	d[s] = 0;
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (Edge neighbor : adjLists[u])
		{
			if(d[neighbor.getEnd()] == INT32_MAX)
			{
				d[neighbor.getEnd()] = d[u] + 1;
				p[neighbor.getEnd()] = u;
				Q.push(neighbor.getEnd());
			}
		}
	}
}
