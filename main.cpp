#include <iostream>
#include <fstream>
#include <ostream>
#include "KwayMerge.h"
#include "FileManager.h"

using namespace std;

int main()
{
	int n, k;
	string input, output, nStr, kStr;
	
	try
	{
		//cout << "Please enter the amount of the elements: " << endl;
		cin >> nStr;
		n = convertToInteger(nStr);
		if (n < 0)
			throw exception("wrong input");

		//cout << "Please enter an integer between 1 to " << n << ":" << endl;
		cin >> kStr;
		k = convertToInteger(kStr);
		if (k < 0 || k > n)
			throw exception("wrong input");

		//cout << "Please enter input file name (including .txt):" << endl;
		cin >> input;

		//cout << "Please enter output file name (including .txt):" << endl;
		cin >> output;

		FileManager f(input, output);
		long int* arr = new long int[n];

		f.readFromFile(arr, n);
		KwayMerge(arr, n, k);
		f.writeToFile(arr, n);
	}
	catch (exception err)
	{
		cout << err.what();
		exit(1);
	}
}

