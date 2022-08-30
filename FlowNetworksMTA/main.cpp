#include <iostream>
#include "DirectedGraph.h"
#include "Utils.h"


// Input is as follows:
// 1. Enter number of vertices.
// 2. Enter number of edges.
// 3. Enter vertex for S (First vertex).
// 4. Enter vertex for T (Last vertex).
// 5. Enter an edge in the following order: startVertex endVertex flow.
// 6. Repeat step 5 until all edges entered.
int main()
{
    int numberOfVertices = 0, numberOfEdges = 0, sName = 0, tName = 0;
    DirectedGraph graphFromUserForDijkstra;
    DirectedGraph graphFromUserForBFS;
    Utils::getFirstData(numberOfVertices, numberOfEdges, sName, tName);
    graphFromUserForDijkstra.makeEmptyGraph(numberOfVertices);
    graphFromUserForDijkstra.makeGraphFromUserInput(numberOfVertices, numberOfEdges);
    graphFromUserForBFS = graphFromUserForDijkstra;
    graphFromUserForDijkstra.fordFalkerson(sName - 1, tName - 1, true);
    graphFromUserForBFS.fordFalkerson(sName - 1, tName - 1, false);
}

