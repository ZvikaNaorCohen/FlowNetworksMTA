#include <iostream>

#include "DirectedGraph.h"


// Comment list:
/* 1. Run checks for numberOfVertices: above 2 [for s,t, and the rest], mispar shalem, etc.
 * 2. Check that is mispar shalem, bigger than 0.
 * 3. Check that sName is smaller than numberOfVertices, misparShalem.
 * 4. Check that vertices are under numberOfVertices, cut is bigger than 0.
 *
 */

int main()
{
    int numberOfVertices = 0, numberOfEdges = 0, sName = 0, tName = 0;
    cin >> numberOfVertices;// 1.
    cin >> numberOfEdges;// 2.
    cin >> sName;// 3.
    cin >> tName;// 3.

    DirectedGraph graphFromUser;
    graphFromUser.makeEmptyGraph(numberOfVertices);
    
    for(int i=0; i<numberOfEdges;i++)
    {
        int startVertex = 0, endVertex = 0, cut = 0; 
        cin >> startVertex >> endVertex >> cut; // 4.

        graphFromUser.addEdge(startVertex-1, endVertex-1, cut);
    }

    vector<int> d, p;

    graphFromUser.runBFS(0, d, p);
    graphFromUser.fordFalkersonUsingBFS(0, 5);

    cout << "TEST DELETE" << endl;

    // Build FlowNetwork

    // Continue App

}
