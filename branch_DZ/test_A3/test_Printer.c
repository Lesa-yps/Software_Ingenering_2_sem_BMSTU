#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "const.h"
#include "Printer.h"

int main(void)
{
    int a[MAX_LEN];
    size_t n;
    char name_file[MAX_LEN_STR + 1];
    FILE *f;
    printf("Input name of file: ");
    fgets(name_file, MAX_LEN_STR + 1, stdin);
    if (name_file[strlen(name_file) - 1] == '\n')
        name_file[strlen(name_file) - 1] = '\0';
    f = fopen(name_file, "w");
    printf("Input count: ");
    scanf("%zu", &n);
    printf("Input numbers:\n");
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Printer(f, a, n);
    fclose(f);
    return OK;
}
