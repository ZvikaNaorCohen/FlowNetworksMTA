#include <iostream>
#include "DirectedGraph.h"
#include "Utils.h"

#define _CRT_SECURE_NO_WARNINGS
#define MAX_CHAR_COUNT 100


int main()
{
    int numberOfVertices = 0, numberOfEdges = 0, sName = 0, tName = 0;
    DirectedGraph graphFromUser;

    Utils::getFirstData(numberOfVertices, numberOfEdges, sName, tName);
    graphFromUser.makeEmptyGraph(numberOfVertices);
    
    for(int i=0; i<numberOfEdges;i++)
    {
        string userShlasha;
        getline(std::cin, userShlasha);
        int startVertex = 0, endVertex = 0, cut = 0;

        if (!Utils::checkUserShlasha(userShlasha, startVertex, endVertex, cut) || 
            !Utils::checkUserNewEdge(startVertex - 1, endVertex - 1, cut, numberOfVertices))
        {
            Utils::invalidInput();
        }
        
        graphFromUser.addEdge(startVertex-1, endVertex-1, cut);
    }

    vector<int> d, p;

    graphFromUser.runBFS(0, d, p);
    graphFromUser.fordFalkersonUsingBFS(0, 5);

    cout << "TEST DELETE" << endl;

    // Build FlowNetwork

    // Continue App

}

