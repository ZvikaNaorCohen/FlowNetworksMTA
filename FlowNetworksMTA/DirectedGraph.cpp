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
	int index = -1;
	for(int i=0; i<adjLists[startVertex].size(); i++)
	{
		if(adjLists[startVertex][i].getEnd() == endVertex)
		{
			index = i;
		}
	}
	if(index == -1)
	{
		Utils::invalidInput();
	}
	else
	{
		adjLists[startVertex].erase(adjLists[startVertex].begin() + index);
	}
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

void DirectedGraph::runDijkstra(int s, vector<int>& d, vector<int>& p)
{
	MaxHeap PQ;
	formatDandP(d, p, adjLists.size(), true);
	d[s] = 0;
	vector<ZugSador*> allGraphZugSador = getAllGraphZugSador(d);
	PQ.Build(allGraphZugSador);
	
	while (!PQ.isEmptyMaxHeap())
	{
		int u = PQ.max()->getStartVertex();
		PQ.deleteMax();
		for (Edge neighbor : adjLists[u])
		{
			int v = neighbor.getEnd();

			if(d[v] < d[u] + neighbor.getKibulShiuri() && d[u] != -1 && neighbor.getKibulShiuri() != 0 && d[v] == -1)
			{
				d[v] = d[u] + neighbor.getKibulShiuri();
				p[v] = u;
				int spotInArr = PQ.getPlaceInArr(v);
				if (spotInArr >= 0)
				{
					PQ.increaseKey(spotInArr, d[v]);
				}
			}
		}
	}
}

void DirectedGraph::formatDandP(vector<int>& d, vector<int>& p, int numberOfVertices, bool dijk)
{
	d.resize(numberOfVertices);
	p.resize(numberOfVertices);
	for (int i = 0; i < numberOfVertices; i++)
	{
		if (dijk)
		{
			d[i] = -1;
		}
		else
		{
			d[i] = INT32_MAX;
		}

		p[i] = -1;
	}
}


vector<ZugSador*> DirectedGraph::getAllGraphZugSador(vector<int>& d)
{
	vector<ZugSador*> vectorToReturn;
	for(int i=0; i<d.size(); i++)
	{
		// Need to emplace back i, kibul_Shiuri minimali == d[i]
		vectorToReturn.emplace_back(new ZugSador(i, d[i]));
	}
	return vectorToReturn;
}


void DirectedGraph::fordFalkerson(int s, int t, bool dijk)
{
	vector<int> d, p;
	int inf = dijk ? -1 : INT32_MAX;
	int numberOfVertices = adjLists.size();
	DirectedGraph graphShiuri;
	graphShiuri.makeEmptyGraph(adjLists.size());
	graphShiuri = buildGraphShiuri(*this);
	d.resize(numberOfVertices); p.resize(numberOfVertices); // newD.resize(numberOfVertices); newP.resize(numberOfVertices);
	if(dijk)
	{
		graphShiuri.runDijkstra(s, d, p);
	}
	else
	{
		graphShiuri.runBFS(s, d, p);
	}
	while (d[t] != inf)
	{
		int kibulShiuri = this->getMinimumKibulShiuri(d, p, t);
		updateEdgesKibulShiuri(kibulShiuri, p, t, graphShiuri);
		formatDandP(d, p, adjLists.size(), true);
		if (dijk)
			graphShiuri.runDijkstra(s, d, p);
		else
			graphShiuri.runBFS(s, d, p);
	}

	vector<int> S, T;
	int maximumFlow = getHatahMinimali(S, T, d, p, s, t, dijk);
	Utils::shareConclusions(S, T, maximumFlow, dijk);
}




int DirectedGraph::getHatahMinimali(vector<int>& S, vector<int>& T, vector<int> d, vector<int> p, int sName, int tName, bool dijk)
{
	int inf = dijk == true ? -1 : INT32_MAX;
	for(int i=0; i<d.size(); i++)
	{
		d[i] == inf ? T.push_back(i) : S.push_back(i);
	}
	return getMaximumFlow(S, T, d, p, sName, tName, dijk);
}

int DirectedGraph::getMaximumFlow(vector<int>& S, vector<int>& T, vector<int> d, vector<int> p, int sName, int tName, bool dijk)
{
	int maximumFlow = 0;
	int flowFromS = 0, flowToT = 0;
	int inf = dijk ? -1 : INT32_MAX;
	// Check if S has kshatot revuiot:
	for(int i=0; i<adjLists.size(); i++)
	{
		for(int j=0; j<adjLists[i].size(); j++)
		{
			if(adjLists[i][j].getEnd() == tName)
			{
				flowToT += adjLists[i][j].getFlow();
			}
		}
		
	}

	return flowToT;
}

int DirectedGraph::getMinimumKibulShiuri(vector<int>& d, vector<int>& p, int t)
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

int DirectedGraph::getMaximumKibulShiuri(vector<int>& d, vector<int>& p, int t)
{
	int startVertex = p[t];
	int endVertex = t;
	int maximumKibulShiuri = 0;
	while (startVertex != -1)
	{
		int kibulShiuri = getEdgeFromGraph(startVertex, endVertex).getCut() - getEdgeFromGraph(startVertex, endVertex).getFlow();
		if (kibulShiuri > maximumKibulShiuri)
		{
			maximumKibulShiuri = kibulShiuri;
		}
		endVertex = startVertex;
		startVertex = p[startVertex];
	}

	return maximumKibulShiuri;
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
