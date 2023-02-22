#include "Data.h"

void Swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void SortedDataGenerator(int a[], int max, int size)
{
	srand((unsigned int)time(NULL));
	a[0] = 1;
	for (int i = 1; i < size; i++)
		a[i] = a[i - 1] + rand() % 2;
}

void NearlySortedDataGenerator(int a[], int max, int size)
{
	SortedDataGenerator(a, max, size);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int pos1 = rand() % size;
		int pos2 = rand() % size;
		Swap(a[pos1], a[pos2]);
	}
}

void ReverseDataGenerator(int a[], int max, int size)
{
	a[0] = max;
	srand((unsigned int)time(NULL));
	for (int i = 1; i < size; i++)
		a[i] = a[i - 1] - rand() % 2;
}

void RandomDataGenerator(int a[], int max, int size)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)
		a[i] = rand() % size;
}