#include <iostream>
#include "DirectedGraph.h"
#include "Utils.h"

#define _CRT_SECURE_NO_WARNINGS
#define MAX_CHAR_COUNT 100


int main()
{
    int numberOfVertices = 0, numberOfEdges = 0, sName = 0, tName = 0;
    string userInput;
    cin >> userInput;
    if (!Utils::getIntFromString(userInput, numberOfVertices))
    {
        // terminate - invalid value.
        exit(1);
    }
    userInput.erase();
    cin >> userInput;
    if(!Utils::getIntFromString(userInput, numberOfEdges))
    {
        // terminate - invalid value.
        exit(1);
    }
    userInput.erase();
    cin >> userInput;
    if (!Utils::getIntFromString(userInput, sName))
    {
        // terminate - invalid value.
        exit(1);
    }
    userInput.erase();
    cin >> userInput;
    if (!Utils::getIntFromString(userInput, tName))
    {
        // terminate - invalid value.
        exit(1);
    }

    if(!Utils::checkUserFirstData(numberOfVertices, numberOfEdges, sName, tName))
    {
        // terminate - invalid value.
        exit(1);
    }

    DirectedGraph graphFromUser;
    graphFromUser.makeEmptyGraph(numberOfVertices);
    
    for(int i=0; i<numberOfEdges;i++)
    {
        char userNewShlasha[MAX_CHAR_COUNT] = {};


        /// BUG:
        /// userNewShlasha isn't being updated with the user input.


        cin.getline(userNewShlasha, MAX_CHAR_COUNT, '\n');
        int startVertex = 0, endVertex = 0, cut = 0;

        if (sscanf_s(userNewShlasha, "%d%d%d", &startVertex, &endVertex, &cut) != 3 ||
            !Utils::checkUserNewEdge(startVertex - 1, endVertex - 1, cut, numberOfVertices))
        {
			// Terminate
            exit(1);
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

