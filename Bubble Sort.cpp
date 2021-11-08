#include <isostream>
#include <time.h> 

void BubbleSort(int a[], int n)
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

void BubbleSort_Timing(int a[], int n)
{
    Start = clock();
    BubbleSort(a, n);
    End = clock();
    Time = ((double)(End - Start)) / CLOCKS_PER_SEC;

    count << "Time Bubble Sort: " << Time;
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
