#include "Utils.h"

#include <iostream>
#include <ostream>
using namespace std;

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

void Utils::invalidInput()
{
	cout << "Invalid Input. " << endl;
	exit(1);
}

void Utils:: getFirstData(int& numberOfVertices, int& numberOfEdges, int& sName, int& tName)
{
	string userInput;
	cin >> userInput;
	if (!getIntFromString(userInput, numberOfVertices))
	{
		invalidInput();
	}
	userInput.erase();
	cin >> userInput;
	if (!getIntFromString(userInput, numberOfEdges))
	{
		invalidInput();
	}
	userInput.erase();
	cin >> userInput;
	if (!getIntFromString(userInput, sName))
	{
		invalidInput();
	}
	userInput.erase();
	cin >> userInput;
	if (!getIntFromString(userInput, tName))
	{
		invalidInput();
	}

	if (!checkUserFirstData(numberOfVertices, numberOfEdges, sName, tName))
	{
		invalidInput();
	}
}

bool Utils::checkUserShlasha(string userInput, int& startVertex, int& endVertex, int& cut)
{
	int index = 0, stringLength = userInput.length();
	bool validInput = true;
	if (userInput[0] >= '0' && userInput[0] <= '9')
	{
		while (index < stringLength && userInput[index] >= '0' && userInput[index] <= '9')
		{
			startVertex += (userInput[index] - '0');
			startVertex *= 10;
			index++;
		}
		startVertex /= 10;

		if (!(userInput[index] == ' ' && index < stringLength))
		{
			validInput = false;
		}
		else
		{
			index++;
			while (index < stringLength && userInput[index] >= '0' && userInput[index] <= '9')
			{
				endVertex += (userInput[index] - '0');
				endVertex *= 10;
				index++;
			}
			endVertex /= 10;
			if (!(userInput[index] == ' ' && index < stringLength))
			{
				validInput = false;
			}
			else
			{
				index++;
				while (index < stringLength && userInput[index] >= '0' && userInput[index] <= '9')
				{
					cut += (userInput[index] - '0');
					cut *= 10;
					index++;
				}
				cut /= 10;
				if (index < stringLength)
				{
					validInput = false;
				}
			}
		}
	}
	else
	{
		validInput = false;
	}
	return validInput;
}