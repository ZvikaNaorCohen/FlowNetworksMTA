#include <iostream>
#include "DirectedGraph.h"
#include "Utils.h"

// #define MAX_CHAR_COUNT 100


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

