#pragma once

struct  Pair
{
	long int* _arr;
	int _arrSize;
	long int _minValue;
};

class Heap
{
private:
	Pair* _heapArr;
	int _heapSize;
	int _maxSize;
	int _allocated;

	static int Left(int pairIndex);
	static int Right(int pairIndex);
	static int Parent(int pairIndex);

	void fix_heap(int toFix);

public:
	Heap(int size);
	~Heap();

	Pair min();
	Pair delete_min();
	int getSize() const { return _heapSize; }
	void insert(Pair pairToAdd);
	void makeEmpty();
	bool isEmpty();
	Pair createPair(long int* arr, int arrSize);
};

