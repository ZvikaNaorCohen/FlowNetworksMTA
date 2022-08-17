// FlowNetworksMTA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "DirectedGraph.h"

int main()
{
    int numberOfVertices = 0, numberOfEdges = 0, sName = 0, tName = 0;
    cin >> numberOfVertices;
    // Run checks for numberOfVertices: above 2 [for s,t, and the rest], mispar shalem, etc.
    cin >> numberOfEdges;
    // Check that is mispar shalem, bigger than 0.
    cin >> sName;
    // Check that sName is smaller than numberOfVertices, misparShalem.
    cin >> tName;
    // check same like sname.

    DirectedGraph graphFromUser;
    // Start receiving SHLASHOT
    for(int i=0; i<numberOfEdges;i++)
    {
        int startVertex = 0, endVertex = 0, cut = 0;
        // Check that vertices are under numberOfVertices, cut is bigger than 0.
        cin >> startVertex >> endVertex >> cut;

        graphFromUser.AddEdge(startVertex, endVertex, cut);
    }

    // Build FlowNetwork

    // Continue App

}
