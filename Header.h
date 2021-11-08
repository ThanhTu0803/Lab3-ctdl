#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <algorithm>

using namespace std;

template <class T>
void HoanVi(T& a, T& b);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

void BubbleSort(int a[], int n);
void BubbleSort_Timing(int a[], int n);
void BubbleSort_Compare(int a[], int n, int& count_compare);

void SelectionSort(int a[], int n);
void SelectionSort_Timing(int a[], int n);
void SelectionSort_Compare(int a[], int n, int& count_compare);

void InsertionSort(int a[], int n);
void InsertionSort_Timing(int a[], int n);
void InsertionSort_Compare(int a[], int n, int& count_compare);

void ShakerSort(int a[], int n);
void ShakerSort_Timing(int a[], int n);
void ShakerSort_Compare(int a[], int n, int& count_compare);

void Heapify(int a[], int n, int i);
void HeapSort(int a[], int n);
void HeapSort_Timing(int a[], int n);
void Heapify_Compare(int a[], int n, int i, int& count_compare);



