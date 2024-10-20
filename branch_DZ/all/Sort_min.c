#include "Sort_min.h"

void Sort_min(int a[], size_t n)
{
    size_t i = 0;
    size_t j;
    int m;
    while (i < (n - 1))
    {
        j = i + 1;
        while (j < n)
        {
            if (a[j] > a[i])
            {
                m = a[i];
                a[i] = a[j];
                a[j] = m;
            }
            j++;
        }
        i++;
    }
}
