#pragma once
#include <cstdint>
#define MAX_SIZE 9999
#include <vector>

#include "ZugSador.h"
#include "Edge.h"
#include <cstdlib>
#include <iostream>
using namespace std;

class MaxHeap
{
	int heapSize = 0;
	std::vector<ZugSador> arr;

public:
	// void emptyMaxHeap();
	ZugSador max()const { return arr[0]; };
	ZugSador getMaxHeapArr(int i) { return arr[i]; }
	int getMaxHeapSize()const { return heapSize; }
	void upFixHeap(int index);
	void downFixHeap(int index);
	void swap(int index1, int index2);
	int getPlaceInArr(int i_EndVertex)const;

	void Build(std::vector<ZugSador>& i_ArrayOfZugSador);
	bool isEmptyMaxHeap()const { return arr.empty(); }
	void deleteMax();
	void increaseKey(int placeInArr, int newKey);
	
	void insert(ZugSador& item);
	void Delete(int i);
	
};

