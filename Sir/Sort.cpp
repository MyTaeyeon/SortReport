#include "Sort.h"

int minValue(int x, int y)
{
	if (x <= y) return x;
	else return y;
}
void Hoanvi(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void selectionSort(int a[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < length; j++)
			if (a[min] > a[j]) min = j;
		Hoanvi(a[min], a[i]);
	}
}

void bubbleSort(int a[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		bool swaped = false;
		for (int j = 0; j < length - i - 1; j++)
			if (a[j] > a[j + 1])
			{
				swaped = true;
				Hoanvi(a[j], a[j + 1]);
			}
		if (!swaped) break;
	}
}

void insertionSort(int a[], int length)
{
	for (int i = 0; i < length; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

void interchangeSort(int a[], int length)
{
	for (int i = 0; i < length - 1; i++)
		for (int j = i + 1; j < length; j++)
			if (a[i] > a[j]) Hoanvi(a[i], a[j]);
}

void merge(int a[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* leftArray = new int[n1];
	int* rightArray = new int[n2];
	for (int i = 0; i < n1; i++) leftArray[i] = a[left + i];
	for (int i = 0; i < n2; i++) rightArray[i] = a[mid + i + 1];

	int i = 0, j = 0, current = left;
	while (i < n1 && j < n2)
		if (leftArray[i] <= rightArray[j]) a[current++] = leftArray[i++];
		else a[current++] = rightArray[j++];
	while (i < n1) a[current++] = leftArray[i++];
	while (j < n2) a[current++] = rightArray[j++];

	delete[] leftArray, rightArray;
}
void merge_sort(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		merge_sort(a, left, mid);
		merge_sort(a, mid + 1, right);

		merge(a, left, mid, right);
	}
}
void mergeSort(int a[], int length)
{
	merge_sort(a, 0, length - 1);
}

void heapify(int a[], int length, int pos)
{
	int largest = pos, left = 2 * pos + 1, right = 2 * pos + 2;
	if (left < length && a[largest] < a[left]) largest = left;
	if (right < length && a[largest] < a[right]) largest = right;
	
	if (largest != pos)
	{
		Hoanvi(a[largest], a[pos]);
		heapify(a, length, largest);
	}
}
void heapSort(int a[], int length)
{
	for (int i = length / 2 - 1; i >= 0; i--) heapify(a, length, i);
	for (int i = length - 1; i > 0; i--)
	{
		Hoanvi(a[0], a[i]);
		heapify(a, i, 0);
	}
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && arr[left] < pivot) left++;
		while (right >= left && arr[right] > pivot) right--;
		if (left >= right) break;
		else
		{
			Hoanvi(arr[left], arr[right]);
			left++;
			right--;
		}
	}
	Hoanvi(arr[left], arr[high]);
	return left;
}
void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}
void quickSort(int a[], int length)
{
	quick_sort(a, 0, length - 1);
}

void countingSort(int input[], int n)
{
	int max = input[0];
	int min = input[0];

	for (int i = 1; i < n; i++)
	{
		if (input[i] > max)
			max = input[i]; // Maximum value in array
		else if (input[i] < min)
			min = input[i]; // Minimum value in array
	}

	int k = max - min + 1; // Size of count array
	int* count_array = new int[k];
	for (int i = 0; i < k; i++) count_array[i] = 0;
	for (int i = 0; i < n; i++)
		count_array[input[i] - min]++; // Store count of each individual input value

	/* Change count_array so that count_array now contains actual
	 position of input values in output array */
	for (int i = 1; i < k; i++)
		count_array[i] += count_array[i - 1];


	// Populate output array using count_array and input array
	int* output = new int[n];
	for (int i = 0; i < n; i++)
	{
		output[count_array[input[i] - min] - 1] = input[i];
		count_array[input[i] - min]--;
	}
	delete[] count_array;

	for (int i = 0; i < n; i++)
		input[i] = output[i];
	delete[] output;
}

int getMax(int a[], int length)
{
	int res = a[0];
	for (int i = 1; i < length; i++)
		if (a[i] > res) res = a[i];
	return res;
}
void counting_sort(int a[], int length, int place)
{
	const int max = 10;
	int count[max] = {0};
	int* output = new int[length];

	for (int i = 0; i < length; i++) count[(a[i] / place) % 10]++;
	for (int i = 1; i < max; i++) count[i] += count[i - 1];

	for (int i = length - 1; i >= 0; i--)
	{
		output[count[(a[i] / place) % 10] - 1] = a[i];
		count[(a[i] / place) % 10]--;
	}
	for (int i = 0; i < length; i++) a[i] = output[i];
	delete[] output;
}
void radixSort(int a[], int length)
{
	int max = getMax(a, length);
	for (int place = 1; max / place > 0; place *= 10)
		counting_sort(a, length, place);
}

void shellSort(int a[], int length)
{
	for (int gap = length / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < length; i++)
		{
			int carry = a[i], j = i;
			for (j; j >= gap && a[j - gap] > carry; j -= gap) a[j] = a[j - gap];
			a[j] = carry;
		}
	}
}

void insertElement(int a[], int left, int right)
{
	for (int i = left; i <= right; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= left && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
void timSort(int a[], int length)
{
	const int GAP = 32;
	for (int i = 0; i < length; i += GAP)
		insertElement(a, i, minValue(i + GAP - 1, length - 1));

	for (int size = GAP; size < length; size *= 2)
		for (int left = 0; left < length; left += 2 * size)
		{
			int mid = left + size - 1;
			int right = minValue(left + 2 * size - 1, length - 1);
			if (mid < right)
			{
				merge(a, left, mid, right);
			}
		}
}

void TWP(int arr[], int m, int n, int& begin, int& end)
{
	int pivot = arr[m];
	begin = m, end = n;

	for (int i = begin + 1; i <= end; i++)
	{
		if (arr[i] < pivot)
		{
			Hoanvi(arr[i], arr[begin]);
			begin++;
		}
		else if (arr[i] > pivot)
		{
			Hoanvi(arr[i], arr[end]);
			end--;
			i--;
		}
	}
}
void three_way_quicksort(int arr[], int m, int n)
{
	if (m >= n)
	{
		return;
	}
	int begin, end;
	TWP(arr, m, n, begin, end);
	three_way_quicksort(arr, m, --begin);
	three_way_quicksort(arr, ++end, n);
}
void ternaryQuickSort(int a[], int length)
{
	three_way_quicksort(a, 0, length - 1);
}