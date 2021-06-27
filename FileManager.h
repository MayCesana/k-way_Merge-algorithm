#pragma once
#include <iostream>
#include <fstream>
#include <istream>
#include "functions.h"

class FileManager
{
private:
	const string _inputFileName;
	const string _outputFileName;

public:
	
	FileManager(const string& inputFileName, const string& outputFileName) 
		:_inputFileName(inputFileName), _outputFileName(outputFileName) {}

	void readFromFile(long int* dest, int size);
	void writeToFile(long int* src, int size);
};

