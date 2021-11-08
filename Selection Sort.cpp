#include <isostream>
#include <time.h> 

void SelectionSort(int a[], int n)
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

void SelectionSort_Timing(int a[], int n)
{
    Start = clock();
    SelectionSort(a, n);
    End = clock();
    Time = ((double)(End - Start)) / CLOCKS_PER_SEC;

    count << "Time Selection Sort: " << Time;
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
