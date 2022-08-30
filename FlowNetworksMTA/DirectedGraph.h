#pragma once
#include "Edge.h"
#include "Utils.h"
#include "MaxHeap.h"
#include <vector>
#include <list>
#include <queue>

using namespace std;

class DirectedGraph
{
	std::vector<std::vector<Edge>> adjLists;

public:
	void makeEmptyGraph(int numberOfVertices);
	std::list<int> getAdjList(int i_Vertex);
	void addEdge(int startVertex, int endVertex, int flow, int cut);
	void removeEdge(int startVertex, int endVertex);
	void runBFS(int s, vector<int>& d, vector<int>& p);
	void runDijkstra(int s, vector<int>& d, vector<int>& p);
	Edge& getEdgeFromGraph(int startVertex, int endVertex);
	void makeGraphFromUserInput(int numberOfVertices, int numberOfEdges);
	static void formatDandP(vector<int>& d, vector<int>& p, int numberOfVertices, bool dijk = false);
	void updateEdgesKibulShiuri(int kibulShiuri, vector<int>& p, int t, DirectedGraph& graphShiuri);
	int getMinimumKibulShiuri(vector<int>& d, vector<int>& p, int t);
	int getMaximumKibulShiuri(vector<int>& d, vector<int>& p, int t);
	DirectedGraph buildGraphShiuri(DirectedGraph originalGraph);
	bool hasEdge(int startVertex, int endVertex);
	void setKibulShiuri(int startVertex, int endVertex, int kibulShiuri);
	int getHatahMinimali(vector<int>& S, vector<int>& T, vector<int> d, vector<int> p, int sName, int tName, bool dijk);
	int getMaximumFlow(vector<int>& S, vector<int>& T, vector<int> d, vector<int> p, int s, int tName, bool dijk);
	void fordFalkerson(int s, int t, bool dijk);
	vector<ZugSador*> getAllGraphZugSador(vector<int>& d);
};

