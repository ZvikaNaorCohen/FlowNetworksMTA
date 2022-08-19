#pragma once
#include <string>

class Utils
{

public:
	static bool getIntFromString(std::string i_UserInput, int& o_OutputInt);
	static bool checkUserNewEdge(int startVertex, int endVertex, int cut, int numberOfVertices);
	static bool checkUserFirstData(int numberOfVertices, int numberOfEdges, int sName, int tName);
	static void invalidInput();
	static void getFirstData(int& numberOfVertices, int& numberOfEdges, int& sName, int& tName);
	static bool checkUserShlasha(std::string input, int& startVertex, int& endVertex, int& cut);
};

