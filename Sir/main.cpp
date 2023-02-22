#include <iostream>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <cstdlib>
// #include "Sort.h"

using namespace std;

void selectionSort(int a[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < length; j++)
			if (a[min] > a[j]) min = j;
		swap(a[min], a[i]);
	}
}

int main()
{
	 string fileName[] = { "1_10m.txt", "2_10m.txt", "3_10m.txt", "4_10m.txt", "5_10m.txt", "6_10m.txt" };
	 ofstream wif("result_10m.csv", ios::app);
	 wif << "Selection sort ";
	 for (int index = 0; index < 6; index++)
	 {
		ifstream rif(fileName[index]);
		int length; rif >> length;
		int* B = new int[length];
		for (int i = 0; i < length; i++) rif >> B[i];
		 rif.close();
		auto begin = chrono::high_resolution_clock::now();
		selectionSort(B, length);
		//bubbleSort(B, length);
		// insertionSort(B, length);
		//interchangeSort(B, length);
		//mergeSort(B, length);
		//heapSort(B, length);
		//quickSort(B, length);
		//ternaryQuickSort(B, length);
		//sort(B, B + length);
		//countingSort(B, length);
		//radixSort(B, length);
		//shellSort(B, length);
		// timSort(B, length);
		auto end = chrono::high_resolution_clock::now();
		delete[] B;
		wif << ", " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
		
		cout << "Test case " << index + 1 << " completed!\n";
	 }
	 wif.close();
	return 0;
}