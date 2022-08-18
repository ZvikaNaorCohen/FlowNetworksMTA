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
	formatDandP(d, p, adjLists.size());
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

void DirectedGraph::formatDandP(vector<int>& d, vector<int>& p, int numberOfVertices)
{
	d.resize(numberOfVertices);
	p.resize(numberOfVertices);
	for (int i = 0; i < numberOfVertices; i++)
	{
		d[i] = INT32_MAX;
		p[i] = -1;
	}
}

void DirectedGraph::fordFalkersonUsingBFS(int s, int t)
{
	vector<int> d, p;
	int numberOfVertices = adjLists.size();
	d.resize(numberOfVertices);
	p.resize(numberOfVertices);
	runBFS(s, d, p);
	while(d[t] != INT32_MAX)
	{
		// Find minimal Cut-Flow
		// Add that minimal to all flows
		int kibulShiuri = getKibulShiuri(d, p, t);
		updateEdgesKibulShiuri(kibulShiuri, p, t);
		formatDandP(d, p, adjLists.size());
	}
}

int DirectedGraph::getKibulShiuri(vector<int>& d, vector<int>& p, int t)
{
	int startVertex = p[t];
	int endVertex = t;
	int minimumKibulShiuri = INT32_MAX;
	while (startVertex != -1)
	{
		int kibulShiuri = getEdgeFromGraph(startVertex, endVertex).getCut() - getEdgeFromGraph(startVertex, endVertex).getFlow();
		if (kibulShiuri < minimumKibulShiuri)
		{
			minimumKibulShiuri = kibulShiuri;
		}
		endVertex = startVertex;
		startVertex = p[startVertex];
	}

	return minimumKibulShiuri;
}

void DirectedGraph::updateEdgesKibulShiuri(int kibulShiuri, vector<int>& p, int t)
{
	
}

Edge& DirectedGraph::getEdgeFromGraph(int startVertex, int endVertex)
{
	int numberOfNeighbors = adjLists[startVertex].size();
	Edge* edgeToReturn = nullptr;
	for(int i=0; i<numberOfNeighbors; i++)
	{
		if(adjLists[startVertex][i].getEnd() == endVertex)
		{
			edgeToReturn = &adjLists[startVertex][i];
		}
	}
	return *edgeToReturn;
}