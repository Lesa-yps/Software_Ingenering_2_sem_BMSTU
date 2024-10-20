#include <stdio.h>
#include <stddef.h>

#include "const.h"
#include "Sorter.h"

int main(void)
{
    int a[MAX_LEN];
    size_t n;
    printf("Input count: ");
    scanf("%zu", &n);
    printf("Input numders:\n");
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Sorter(a, n);
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return OK;
}
