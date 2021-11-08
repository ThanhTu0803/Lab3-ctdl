#include <isostream>
#include <time.h> 

void Heapify(int a[], int n, int i)
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

        Heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify_Timing(a, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        HoanVi(a[0], a[i]);

        Heapify(a, i, 0);
    }
}

void HeapSort_Timing(int a[], int n)
{
    Start = clock();
    HeapSort(a, n);
    End = clock();
    Time = ((double)(End - Start)) / CLOCKS_PER_SEC;

    count << "Time Heap Sort: " << Time;
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