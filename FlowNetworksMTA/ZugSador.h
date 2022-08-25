#pragma once
class ZugSador
{
	int startVertex;
	int key;
	int spotInArr;

public:
	ZugSador(int vertex, int dVertex) : startVertex(vertex), key(dVertex) {}
	void setArrSpot(int spot) { spotInArr = spot; }
	void setKey(int setKey) { key = setKey; }

	int getKey()const { return key; }
	int getStartVertex()const { return startVertex; }
	int getSpotInArr()const { return spotInArr; }
};

