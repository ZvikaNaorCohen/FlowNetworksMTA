#include "DirectedGraph.h"

void DirectedGraph::MakeEmptyGraph(int i_NumberOfVertices)
{

}

AdjacencyNode* DirectedGraph::GetAdjList(int i_Vertex)
{
	list<AdjacencyNode*>::iterator iterator = m_GraphNodesList.begin();
	advance(iterator, i_Vertex);
	return *iterator;
}

void DirectedGraph::AddEdge(int i_StartVertex, int i_EndVertex, int i_Cut)
{
	
}

void DirectedGraph::RemoveEdge(int i_StartVertex, int i_EndVertex)
{
	
}