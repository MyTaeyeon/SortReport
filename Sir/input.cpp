#include <iostream>
#include "Data.h"
#include <fstream>

using namespace std;

int main()
{
	cout << "=============== RANDOM ARRAY ============\n";
	cout << "Usage: <numbers_of_elements>  <max_value>  [mode]  <file_name_output>\n";
	cout << "\tmode: 0: sorted\n\t      1: nearly sorted\n\t      2: reverse - descending\n\t      3: random\n";
	cout << "=============== RANDOM ARRAY ============\n";

	int length, max, mode;
	string FileName;
	
	cout << ">>> "; cin >> length >> max >> mode >> FileName;
	int* A = new int[length];

	switch (mode)
	{
	case 0:
		SortedDataGenerator(A, max, length);
		break;
	case 1:
		NearlySortedDataGenerator(A, max, length);
		break;
	case 2:
		ReverseDataGenerator(A, max, length);
		break;
	case 3:
		RandomDataGenerator(A, max, length);
		break;
	default:
		cout << "There's no option " << mode << ".\n";
		break;
	}

	ofstream wif(FileName);
	if (!wif)
	{
		cout << "Can't open " << FileName << endl;
	}
	wif << length << endl;
	for (int i = 0; i < length; i++) wif << A[i] << " ";
	wif.close();

	delete[] A;
	return 0;
}