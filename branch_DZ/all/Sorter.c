#include "Sorter.h"

void Sorter(int a[], size_t n)
{
    size_t i = 0;
    size_t j = 0;
    int a_ch[MAX_LEN];
    size_t n_ch = 0;
    int a_nch[MAX_LEN];
    size_t n_nch = 0;
    while (i < n)
    {
        if (a[i] % 2 == 0)
            a_ch[n_ch++] = a[i];
        else
            a_nch[n_nch++] = a[i];
        i++;
    }
    if (n_ch > 1)
        Sort_max(a_ch, n_ch);
    if (n_nch > 1)
        Sort_min(a_nch, n_nch);

    while (j < n_ch)
    {
        a[j] = a_ch[j];
        j++;
    }
    while ((j - n_ch) < n_nch)
    {
        a[j] = a_nch[j - n_ch];
        j++;
    }
}
