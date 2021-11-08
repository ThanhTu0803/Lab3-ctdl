#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <algorithm>

using namespace std;

template <class T>
void HoanVi(T& a, T& b)
{
    T x = a;
    a = b;
    b = x;
}

//-------------------------------------------------

// Hàm phát sinh m?ng d? li?u ng?u nhiên
void GenerateRandomData(int a[], int n)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
}

// Hàm phát sinh m?ng d? li?u có th? t? tang d?n
void GenerateSortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

// Hàm phát sinh m?ng d? li?u có th? t? ngu?c (gi?m d?n)
void GenerateReverseData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = n - 1 - i;
    }
}

// Hàm phát sinh m?ng d? li?u g?n nhu có th? t?
void GenerateNearlySortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int r1 = rand() % n;
        int r2 = rand() % n;
        HoanVi(a[r1], a[r2]);
    }
}

void GenerateData(int a[], int n, int dataType)
{
    switch (dataType)
    {
    case 0:	// ng?u nhiên
        GenerateRandomData(a, n);
        break;
    case 1:	// có th? t?
        GenerateSortedData(a, n);
        break;
    case 2:	// có th? t? ngu?c
        GenerateReverseData(a, n);
        break;
    case 3:	// g?n nhu có th? t?
        GenerateNearlySortedData(a, n);
        break;
    default:
        printf("Error: unknown data type!\n");
    }
}

void BubbleSort_Timing(int a[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                HoanVi(a[j], a[j + 1]);
                swapped = true;
            }
        }

        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}

void InsertionSort_Timing(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (a[j] > key && j >= 0)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void SelectionSort_Timing(int a[], int n)
{
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        HoanVi(a[min_idx], a[i]);
    }
}

void Heapify_Timing(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        HoanVi(a[i], a[largest]);

        Heapify_Timing(a, n, largest);
    }
}

void HeapSort_Timing(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify_Timing(a, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        HoanVi(a[0], a[i]);

        Heapify_Timing(a, i, 0);
    }
}

void ShakerSort_Timing(int a[], int n)
{
    int left = 0;
    int right = n - 1;
    int k = 0;
    for (int i = left; i <= right; i++)
    {
        bool swapped = false;
        //day max ve cuoi mang
        for (int j = left; j < right; j++)
            if (a[j] > a[j + 1])
            {
                swapped = true;
                HoanVi(a[j], a[j + 1]);
                k = j;
            }
        if (!swapped)
            return;
        right = k;
        //day min ve dau mang
        swapped = false;
        for (int j = right; j > left; j--)
            if (a[j] < a[j - 1])
            {
                swapped = true;
                HoanVi(a[j], a[j - 1]);
                k = j;
            }
        if (!swapped)
            return;
        left = k;
    }
}



void BubbleSort_Compare(int a[], int n, int& count_compare)
{
    bool swapped;
    for (int i = 0; ++count_compare && i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; ++count_compare && j < n - i - 1; j++)
        {
            if (++count_compare && a[j] > a[j + 1])
            {
                HoanVi(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (++count_compare && swapped == false)
            break;
    }
}

void InsertionSort_Compare(int a[], int n, int& count_compare)
{
    for (int i = 1; ++count_compare && i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while ((++count_compare && a[j] > key) && (++count_compare && j >= 0))
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void SelectionSort_Compare(int a[], int n, int& count_compare)
{
    // One by one move boundary of unsorted subarray
    for (int i = 0; ++count_compare && i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; ++count_compare && j < n; j++)
            if (++count_compare && a[j] < a[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        HoanVi(a[min_idx], a[i]);
    }
}

void Heapify_Compare(int a[], int n, int i, int& count_compare)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if ((++count_compare && l < n) && (++count_compare && a[l] > a[largest]))
        largest = l;

    if ((++count_compare && r < n) && (++count_compare && a[r] > a[largest]))
        largest = r;

    if (++count_compare && largest != i)
    {
        HoanVi(a[i], a[largest]);

        Heapify_Compare(a, n, largest, count_compare);
    }
}

void HeapSort_Compare(int a[], int n, int& count_compare)
{
    for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
        Heapify_Compare(a, n, i, count_compare);

    for (int i = n - 1; ++count_compare && i >= 0; i--)
    {
        HoanVi(a[0], a[i]);
        Heapify_Compare(a, i, 0, count_compare);
    }
}
void ShakerSort_Compare(int a[], int n, int& count_compare)
{
    int left = 0;
    int right = n - 1;
    int k = 0;
    for (int i = left; ++count_compare && i <= right; i++)
    {
        bool swapped = false;
        //day max ve cuoi mang
        for (int j = left; ++count_compare && j < right; j++)
            if (++count_compare && a[j] > a[j + 1])
            {
                swapped = true;
                HoanVi(a[j], a[j + 1]);
                k = j;
            }
        if (++count_compare && !swapped)
            return;
        right = k;
        //day min ve dau mang
        swapped = false;
        for (int j = right; ++count_compare && j > left; j--)
            if (a[j] < a[j - 1])
            {
                swapped = true;
                HoanVi(a[j], a[j - 1]);
                k = j;
            }
        if (++count_compare && !swapped)
            return;
        left = k;
    }
}

void Sort(int a[], int n, int k)
{
    switch (k) {
    case 0:
        BubbleSort_Timing(a, n);
        break;
    case 1:
        InsertionSort_Timing(a, n);
        break;
    case 2:
        SelectionSort_Timing(a, n);
        break;
    case 3:
        HeapSort_Timing(a, n);
        break;
    case 4:
        ShakerSort_Timing(a, n);
        break;
    }
}

int main()
{
    int n{}, left, right;
    clock_t start, end;
    double time;
    int datasize[6] = { 10000,30000,50000,100000,300000,500000 };
    int count_compare = 0;
    for (int i = 0; i <= 3; i++)
    {
        int* a = new int[datasize[i]];
        switch (i)
        {
        case 0:
            //GenerateRandomData(a, n);
            cout << "Generate Random Data\n";
            break;
        case 1:
            //GenerateSortedData(a, n);
            cout << "Generate Sorted Data\n";
            break;
        case 2:
            //GenerateReverseData(a, n);
            cout << "Generate Reverse Data\n";
            break;
        case 3:
            //GenerateNearlySortedData(a, n);
            cout << "Generate Nearly Sorted Data\n";
            break;
        default:
            break;
        }
        for (int j = 0; j < 6; j++)
        {
            switch (j)
            {
            case 0:
                cout << "==========Data size 10000==========\n";
                break;
            case 1:
                cout << "==========Data size 30000==========\n";
                break;
            case 2:
                cout << "==========Data size 50000==========\n";
                break;
            case 3:
                cout << "==========Data size 100000==========\n";
                break;
            case 4:
                cout << "==========Data size 300000==========\n";
                break;
            case 5:
                cout << "==========Data size 500000==========\n";
                break;
            default:
                break;
            }
            for (int h = 0; h < 5; h++)
            {
                int* a = new int[datasize[j]];
                start = clock();
                Sort(a, datasize[j], h);
                end = clock();
                time = ((double)(end - start)) / CLOCKS_PER_SEC;

                switch (h) {
                case 0:
                    cout << "Time bubbble sort: " << time << endl;
                    break;
                case 1:
                    cout << "Time insertion sort: " << time << endl;
                    break;
                case 2:
                    cout << "Time selection sort: " << time << endl;
                    break;
                case 3:
                    cout << "Time heap sort: " << time << endl;
                    break;
                case 4:
                    cout << "Time shaker sort: " << time << endl;
                    break;
                }
                delete[]a;
            }

            /*system("pause");
            system("cls");*/
        }
    }
}





