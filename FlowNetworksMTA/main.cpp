#include <iostream>
#include "DirectedGraph.h"
#include "Utils.h"

#define MAX_CHAR_COUNT 100


int main()
{
    int numberOfVertices = 0, numberOfEdges = 0, sName = 0, tName = 0;
    DirectedGraph graphFromUser;
    vector<int> d, p;

    Utils::getFirstData(numberOfVertices, numberOfEdges, sName, tName);
    graphFromUser.makeEmptyGraph(numberOfVertices);
    graphFromUser.makeGraphFromUserInput(numberOfVertices, numberOfEdges);
    graphFromUser.fordFalkersonUsingBFS(sName-1, tName-1);
    graphFromUser.fordFalkersonUsingDijkstra(sName - 1, tName - 1);

}

