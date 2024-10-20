#include "Printer.h"

void Printer(FILE *f, int a[], size_t n)
{
    size_t i = 0;
    while (i < n)
        fprintf(f, "%d ", a[i++]);
    fprintf(f, "\n");
}
