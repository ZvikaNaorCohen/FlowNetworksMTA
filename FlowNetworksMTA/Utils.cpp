#include "Utils.h"


bool Utils::getIntFromString(std::string i_UserInput, int& o_OutputInt)
{
	int index = 0, stringLength = i_UserInput.length();
	int answer = 0;
	bool validInput = true;
	if (i_UserInput[0] >= '0' && i_UserInput[0] <= '9')
	{
		while (index < stringLength && i_UserInput[index] >= '0' && i_UserInput[index] <= '9')
		{
			answer += (i_UserInput[index] - '0');
			answer *= 10;
			index++;
		}
		answer /= 10;
		if (index < stringLength)
		{
			validInput = false;
		}
	}
	else
	{
		validInput = false;
	}
	if (validInput)
	{
		o_OutputInt = answer;
	}
	return validInput;
}

bool Utils::checkUserNewEdge(int startVertex, int endVertex, int cut, int numberOfVertices)
{
	return startVertex <= numberOfVertices && endVertex <= numberOfVertices && cut > 0;
}

bool Utils::checkUserFirstData(int numberOfVertices, int numberOfEdges, int sName, int tName)
{
	return numberOfVertices >= 2 && numberOfEdges >= 0 && sName <= numberOfVertices && tName <= numberOfVertices;
}