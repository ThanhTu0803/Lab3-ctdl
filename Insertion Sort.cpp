#include <isostream>
#include <time.h> 

void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && a[j] > key )
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void InsertionSort_Timing(int a[], int n)
{
    Start = clock();
    InsertionSort(a, n);
    End = clock();
    Time = ((double)(End - Start)) / CLOCKS_PER_SEC;

    count << "Time Insertion Sort: " << Time;
}

void InsertionSort_Compare(int a[], int n, int& count_compare)
{
    for (int i = 1; ++count_compare && i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while ((++count_compare && a[j] > key) && (++count_compare && j >= 0))
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
