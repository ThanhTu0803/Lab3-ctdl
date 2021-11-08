#include <isostream>
#include <time.h> 

void ShakerSort(int a[], int n)
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

void ShakerSort_Timing(int a[], int n)
{
    Start = clock();
    SharkeSort(a, n);
    End = clock();
    Time = ((double)(End - Start)) / CLOCKS_PER_SEC;

    count << "Time Shaker Sort: " << Time;
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
