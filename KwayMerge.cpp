#include "KwayMerge.h"

void KwayMerge(long int* arr, int n, int k)
{
	if (n < k)
	{
		QuickSort(arr, 0, n-1);
	}
	else
	{
		Heap minHeap(k); 
		int kArrSize = n / k;
		int remain = n - (k * kArrSize);

		for (int i = 0; i < k; i++)
		{
			Pair newPair;
			if (i == k - 1)
			{
				KwayMerge(arr + i * kArrSize, kArrSize + remain, k);
				newPair = minHeap.createPair(arr + i * kArrSize, kArrSize + remain);
			}
			else
			{
				KwayMerge(arr + i * kArrSize, kArrSize, k);
				newPair = minHeap.createPair(arr + i * kArrSize, kArrSize);
			}

			minHeap.insert(newPair);
		}
		
		long int* temp = new long int[n];
		kMerge(temp, minHeap);

		for (int i = 0; i < n; i++)
		{
			arr[i] = temp[i];
		}
	}
}

void kMerge(long int* arr, Heap& minHeap)
{
	Pair min;
	int arrInd = 0;
	while (!minHeap.isEmpty())
	{
		min = minHeap.delete_min();
		arr[arrInd] = min._minValue;
		(min._arr)++;
		min._arrSize--;

		if (min._arrSize > 0)
		{
			min._minValue = *(min._arr);
			minHeap.insert(min);
		}

		arrInd++;
	}
}

