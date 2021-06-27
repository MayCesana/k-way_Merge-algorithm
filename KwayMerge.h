#pragma once
#include "Heap.h"
#include "functions.h";

//This function implements the KwayMerge algorithem
void KwayMerge(long int* arr, int n, int k);
//This function merges k arrays into 1 sorted array using minimum heap
void kMerge(long int* arr, Heap& minHeap);
 