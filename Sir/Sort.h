#pragma once

int minValue(int, int);
void Hoanvi(int& x, int& y);

void selectionSort(int Array[], int length);

void bubbleSort(int Array[], int length);

void insertionSort(int Array[], int length);

void interchangeSort(int Array[], int length);

void merge(int Array[], int left, int mid, int right);
void merge_sort(int Array[], int left, int right);
void mergeSort(int Array[], int length);

void heapify(int Array[], int length, int pos);
void heapSort(int Array[], int length);

int partition(int Array[], int low, int high);
void quick_sort(int Array[], int low, int high);
void quickSort(int Array[], int length);

void countingSort(int Array[], int length);

int getMax(int Array[], int length);
void counting_sort(int Array[], int length, int place); // this for radix sort
void radixSort(int Array[], int length);

void shellSort(int Array[], int length);

void insertElement(int Array[], int left, int right);
void timSort(int Array[], int length);

void TWP(int arr[], int m, int n, int& begin, int& end);
void three_way_quicksort(int arr[], int m, int n);
void ternaryQuickSort(int Array[], int length);