#include "FileManager.h"

using namespace std;

void FileManager::readFromFile(long int* dest, int size)
{
	ifstream inputFile;
	string numberStr;

	inputFile.open(_inputFileName);
	if (!inputFile)
	{
		throw exception("Error openning file");
	}
	else
	{
		for (int i = 0; i < size; ++i)
		{
			getline(inputFile, numberStr);
			if (inputFile.fail()) //if there is less numbers than n or error with reading
			{
				inputFile.close();
				throw exception("wrong input");
			}
			
			int number = convertToInteger(numberStr.c_str());
			dest[i] = number;
		}
	}

	inputFile.close();
}

void FileManager::writeToFile(long int* src, int size)
{
	ofstream outputFile;
	outputFile.open(_outputFileName);

	if (!outputFile)
	{
		outputFile.close();
		throw exception("error openning file");
	}
	for (int i = 0; i <size; ++i)
	{
		outputFile << src[i] << endl;
	}

	outputFile.close();
}
