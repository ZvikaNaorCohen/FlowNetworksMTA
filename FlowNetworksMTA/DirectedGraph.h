#pragma once
#include <list>
#include "AdjacencyNode.h"

using namespace std;

class DirectedGraph
{
	list<AdjacencyNode*> m_GraphNodesList;


public:
	void MakeEmptyGraph(int i_NumberOfVertices);
	AdjacencyNode* GetAdjList(int i_Vertex);
	void AddEdge(int i_StartVertex, int i_EndVertex, int i_Cut);
	void RemoveEdge(int i_StartVertex, int i_EndVertex);

};

