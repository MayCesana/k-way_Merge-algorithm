#include "Heap.h"
#include <iostream>

using namespace std;

Heap::Heap(int size)
{
	_heapSize = 0;
	_maxSize = size;
	_allocated = 1;
	_heapArr = new Pair[size];
}

Heap::~Heap()
{
	if (_allocated == 1)
	{
		delete[] _heapArr;
	}
		
	_heapArr = nullptr;
}

void Heap::fix_heap(int toFix)
{
	int currMin = toFix, left = Left(toFix), right = Right(toFix);

	if (left < _heapSize && _heapArr[left]._minValue && _heapArr[left]._minValue < _heapArr[currMin]._minValue)
		currMin = left;

	if (right < _heapSize && _heapArr[right]._minValue && _heapArr[right]._minValue < _heapArr[currMin]._minValue)
		currMin = right;

	if (currMin != toFix)
	{
		Pair tmp = _heapArr[toFix];
		_heapArr[toFix] = _heapArr[currMin];
		_heapArr[currMin] = tmp;
		fix_heap(currMin);
	}
}

int Heap::Parent(int pairIndex)
{
	return (pairIndex - 1) / 2;
}

int Heap::Left(int pairIndex)
{
	return (2 * pairIndex + 1);
}

int Heap::Right(int pairIndex)
{
	return (2 * pairIndex + 2);
}

Pair Heap::delete_min()
{
	if (_heapSize < 1)
	{
		throw exception("The heap is empty");
	}
		
	else
	{
		Pair min = _heapArr[0];
		_heapSize--;
		_heapArr[0] = _heapArr[_heapSize];
		fix_heap(0);
		return min;
	}
}

Pair Heap::min()
{
	return _heapArr[0];
}

void Heap::insert(Pair pairToAdd)
{
	if (_heapSize == _maxSize)
	{
		cout << "Heap is full!" << endl;
	}
	else
	{
		int i = _heapSize;
		_heapSize++;

		while (i > 0 && _heapArr[Parent(i)]._minValue > pairToAdd._minValue)
		{
			_heapArr[i] = _heapArr[Parent(i)];
			i = Parent(i);
		}

		_heapArr[i] = pairToAdd;
	}
}

void Heap::makeEmpty()
{
	if (_heapArr != nullptr)
	{
		delete[] _heapArr;
	}

	_heapArr = new Pair[_maxSize];
	_heapSize = 0;
}

bool Heap::isEmpty()
{
	return (_heapSize == 0);
}

Pair Heap::createPair(long int* arr, int arrSize)
{
	Pair newPair;
	newPair._arr = arr;
	newPair._arrSize = arrSize;
	newPair._minValue = arr[0];

	return newPair;
}



