#pragma once
#include <string>
#include <iostream>
#include "Heap.h"

using namespace std;

void QuickSort(long int arr[], int left, int right);
int partition(long int arr[], int left, int right);
void swap(long int& num1, long int& num2);
long int convertToInteger(const string& str);