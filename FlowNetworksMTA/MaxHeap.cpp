#include "MaxHeap.h"


//void MaxHeap::emptyMaxHeap()
//{
//	Edge* tmp = new Edge();
//	for (int i = 0; i < MAX_SIZE; i++)
//		arr[i] = tmp;
//}

void MaxHeap::insert(ZugSador& item)
{
	if (heapSize == MAX_SIZE - 1)
	{
		std::cout << "wrong input" << endl;
		exit(1);
	}
	ZugSador tmp = item;
	tmp.setArrSpot(heapSize);
	arr[heapSize] = tmp;
	upFixHeap(heapSize);
	heapSize++;
}

void MaxHeap::upFixHeap(int index)
{
	int parent = ((index - 1) / 2);
	if (index && arr[parent].getKey() < arr[index].getKey())
	{
		swap(index, parent);
		upFixHeap(parent);
	}
}

int MaxHeap::getPlaceInArr(int i_EndVertex)const
{
	int heapSize = arr.size();
	for (int i = 0; i < heapSize; i++)
	{
		if (arr[i].getStartVertex() == i_EndVertex)
			return i;
	}
	return -1;
}


void MaxHeap::deleteMax()
{
	if (heapSize == 0)
	{
		std::cout << "wrong input" << endl;
		exit(1);
	}
	swap(0, heapSize - 1);
	heapSize--;
	arr.erase(arr.begin() + heapSize);
	downFixHeap(0);
}

void MaxHeap::downFixHeap(int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int largest = index;
	if (left < heapSize && arr[left].getKey() >= arr[index].getKey())
	{
		largest = left;
	}
	if (right < heapSize && arr[right].getKey() >= arr[largest].getKey())
	{
		largest = right;
	}
	if (largest != index)
	{
		swap(index, largest);
		downFixHeap(largest);
	}
}


void MaxHeap::Delete(int i)
{
	arr[i] = arr[heapSize - 1];
	arr[i].setArrSpot(i);
	heapSize--;
	arr.erase(arr.begin() + heapSize);
	downFixHeap(i);
}

void MaxHeap::swap(int index1, int index2)
{
	ZugSador tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
	arr[index2].setArrSpot(index2);
	arr[index1].setArrSpot(index1);
}

void MaxHeap::Build(vector<ZugSador>& i_ArrayOfZugSador)
{
	int arrSize = i_ArrayOfZugSador.size();
	heapSize = i_ArrayOfZugSador.size();
	arr = i_ArrayOfZugSador;
	for (int i = (arrSize / 2) - 1; i >= 0; i--)
	{
		downFixHeap(i);
	}

	for(int i=0; i<i_ArrayOfZugSador.size(); i++)
	{
		i_ArrayOfZugSador[i].setArrSpot(i);
	}
}

void MaxHeap::increaseKey(int placeInArr, int newKey)
{
	if (placeInArr < arr.size())// && arr[placeInArr] != nullptr)
	{
		arr[placeInArr].setKey(newKey);
		upFixHeap(placeInArr);
	}
	else
	{
		cout << "Wrong input. Trying to decrease an invalid spot in heap. " << endl;
		exit(1);
	}
}