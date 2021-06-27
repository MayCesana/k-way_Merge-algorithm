#include "functions.h"
using namespace std;

void QuickSort(long int arr[], int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int partition(long int arr[], int left, int right)
{
	int pivot = left, index = right;

	while (pivot != index)
	{
		if (pivot < index)
		{
			if (arr[pivot] > arr[index])
			{
				swap(arr[pivot], arr[index]);
				swap(pivot, index);
				index++;
			}
			else
				index--;
		}
		else
		{
			if (arr[pivot] < arr[index])
			{
				swap(arr[pivot], arr[index]);
				swap(pivot, index);
				index--;
			}
			else
				index++;
		}
	}

	return pivot;
}

void swap(long int& num1, long int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

long int convertToInteger(const string& str)
{
	char c;
	int index = 0;

	c = str[index];
	while (c != '\0')
	{
		if (index == 0 && c == '-')
		{
			c = str[++index];
		}
		else if (isdigit(c))
		{
			c = str[++index];
		}
		else
		{
			throw exception("wrong input");
		}
	}

	return atol(str.c_str());
}