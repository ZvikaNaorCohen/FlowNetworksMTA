#pragma once
#include "ZugSador.h"
#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 9999


class MaxHeap
{
	int heapSize = 0;
	ZugSador* arr[MAX_SIZE] = { 0 };

public:
	ZugSador* getMaxHeapArr(int i) { return arr[i]; }
	bool isEmptyMaxHeap()const { return heapSize == 0; }
	ZugSador* max()const { return arr[0]; };
	void Build(vector<ZugSador*>& allGraphZugSador);
	int getPlaceInArr(int i_EndVertex)const;
	int getMaxHeapSize()const { return heapSize; }
	void increaseKey(int i_PlaceInArr, int i_NewKey);
	void insert(ZugSador& item);
	void deleteMax();
	void upFixHeap(int index);
	void downFixHeap(int index);
	void Delete(int i);
	void swap(int index1, int index2);
};

