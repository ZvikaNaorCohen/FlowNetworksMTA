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

void DirectedGraph::addEdge(int startVertex, int endVertex, int flow, int cut)
{
	adjLists[startVertex].push_back(Edge(startVertex, endVertex, flow, cut));
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
			if(d[neighbor.getEnd()] == INT32_MAX && neighbor.getKibulShiuri() != 0)
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
	DirectedGraph graphShiuri;
	graphShiuri.makeEmptyGraph(adjLists.size());
	graphShiuri = buildGraphShiuri(*this);
	d.resize(numberOfVertices);
	p.resize(numberOfVertices);
	graphShiuri.runBFS(s, d, p);
	while(d[t] != INT32_MAX)
	{
		int kibulShiuri = this->getKibulShiuri(d, p, t);
		updateEdgesKibulShiuri(kibulShiuri, p, t, graphShiuri);
		formatDandP(d, p, adjLists.size());
		graphShiuri.runBFS(s, d, p); // NEED TO DELETE KSHATOT REVUIOT !!!!
	}

	// Share conclusions.
	vector<int> S, T;
	int maximumFlow = getHatahMinimali(S, T, d, p, s);
	Utils::shareConclusions(S, T, maximumFlow, true);
}

int DirectedGraph::getHatahMinimali(vector<int>& S, vector<int>& T, vector<int> d, vector<int> p, int sName)
{
	int maximumFlow = 0;
	for(int i=0; i<d.size(); i++)
	{
		d[i] == INT32_MAX ? T.push_back(i) : S.push_back(i);
	}
	for (int i = 0; i < p.size(); i++)
	{
		if(p[i] == sName)
		{
			maximumFlow += getEdgeFromGraph(p[i], i).getFlow();
		}
	}
	return maximumFlow;
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

void DirectedGraph::updateEdgesKibulShiuri(int kibulShiuri, vector<int>& p, int t, DirectedGraph& graphShiuri)
{
	// Seif B PAGE 158
	int startVertex = p[t];
	int endVertex = t;
	while(startVertex != -1)
	{
		int currentFlow = getEdgeFromGraph(startVertex, endVertex).getFlow();
		getEdgeFromGraph(startVertex, endVertex).setFlow(currentFlow + kibulShiuri); // f(u,v) = f(u,v) + Cf(P)
		int newFlow = getEdgeFromGraph(startVertex, endVertex).getFlow();
		getEdgeFromGraph(endVertex, startVertex).setFlow(newFlow * -1); // f(v,u) = -f(u,v)

		endVertex = startVertex;
		startVertex = p[startVertex];
	}

	startVertex = p[t];
	endVertex = t;
	// Seif C PAGE 158
	while(startVertex != -1)
	{
		int edgeUVCut = getEdgeFromGraph(startVertex, endVertex).getCut();
		int edgeUVFlow = getEdgeFromGraph(startVertex, endVertex).getFlow();
		int edgeVUCut = getEdgeFromGraph(endVertex, startVertex).getCut();
		int edgeVUFlow = getEdgeFromGraph(endVertex, startVertex).getFlow();

		
		graphShiuri.setKibulShiuri(startVertex, endVertex, edgeUVCut - edgeUVFlow); // Cf(u,v) = C(u,v) - f(u,v)
		graphShiuri.setKibulShiuri(endVertex, startVertex, edgeVUCut - edgeVUFlow); // Cf(v,u) = C(v,u) - f(v,u)

		if(graphShiuri.hasEdge(startVertex, endVertex) && graphShiuri.getEdgeFromGraph(startVertex, endVertex).getKibulShiuri() == 0)
		{
			graphShiuri.removeEdge(startVertex, endVertex);
		}
		if (graphShiuri.hasEdge(endVertex, startVertex) && graphShiuri.getEdgeFromGraph(endVertex, startVertex).getKibulShiuri() == 0)
		{
			graphShiuri.removeEdge(endVertex, startVertex);
		}

		endVertex = startVertex;
		startVertex = p[startVertex];
	}

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

void DirectedGraph::makeGraphFromUserInput(int numberOfVertices, int numberOfEdges)
{
	for (int i = 0; i < numberOfEdges; i++)
	{
		string userShlasha;
		getline(std::cin >> std::ws, userShlasha);
		int startVertex = 0, endVertex = 0, cut = 0;

		if (!Utils::checkUserShlasha(userShlasha, startVertex, endVertex, cut) ||
			!Utils::checkUserNewEdge(startVertex - 1, endVertex - 1, cut, numberOfVertices))
		{
			Utils::invalidInput();
		}

		addEdge(startVertex - 1, endVertex - 1, 0, cut);
	}

	for (int i = 0; i < adjLists.size(); i++) // Add Kshatot Anti-Makbilot
	{
		for(int j=0; j<adjLists[i].size(); j++)
		{
			if(hasEdge(i,adjLists[i][j].getEnd()) && !hasEdge(adjLists[i][j].getEnd(), i))
			{
				addEdge(adjLists[i][j].getEnd(), i, 0, 0); 
			}
		}
	}
}

DirectedGraph DirectedGraph::buildGraphShiuri(DirectedGraph originalGraph)
{
	DirectedGraph graphShiuri;
	graphShiuri.makeEmptyGraph(adjLists.size());
	int numberOfVertices = originalGraph.adjLists.size();
	for(int i=0; i<numberOfVertices; i++)
	{
		for (int j = 0; j < originalGraph.adjLists[i].size(); j++)
		{
			int cut = originalGraph.adjLists[i][j].getCut();
			int flow = originalGraph.adjLists[i][j].getFlow();
			graphShiuri.addEdge(i, originalGraph.adjLists[i][j].getEnd(), 0, 0);
			graphShiuri.setKibulShiuri(i, originalGraph.adjLists[i][j].getEnd(), cut - flow);
		}
	}

	return graphShiuri;
}

bool DirectedGraph::hasEdge(int startVertex, int endVertex)
{
	bool answer = false;
	for(int i=0; i<adjLists[startVertex].size(); i++)
	{
		if(adjLists[startVertex][i].getEnd() == endVertex)
		{
			answer = true;
		}
	}
	return answer;
}

void DirectedGraph::setKibulShiuri(int startVertex, int endVertex, int kibulShiuri)
{
	for (int i = 0; i < adjLists[startVertex].size(); i++)
	{
		if (adjLists[startVertex][i].getEnd() == endVertex)
		{
			adjLists[startVertex][i].setKibulShiuri(kibulShiuri);
		}
	}
}
