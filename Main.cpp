#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <algorithm>
#include "Header.h"

int main()
{
    int count_compare = 0;
    int n = 1000;
    int a[n];
    GenerateRandomData(a, n);
    SelectionSort_Compare(a, n, count_compare);
    cout << count_compare;
    return 0;
}