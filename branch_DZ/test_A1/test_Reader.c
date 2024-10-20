#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "const.h"
#include "Reader.h"

int main(void)
{
    int rc = OK;
    int first = 0;
    int a[MAX_LEN];
    size_t n;
    char name_file[MAX_LEN_STR + 1];
    FILE *f;
    printf("Input name of file: ");
    if (fgets(name_file, MAX_LEN_STR + 1, stdin) && name_file[0] != '\n')
    {
        if (name_file[strlen(name_file) - 1] == '\n')
            name_file[strlen(name_file) - 1] = '\0';
        f = fopen(name_file, "r");
        if (f == NULL)
        {
            printf("Error with exist file\n");
            return EXIST1_ERROR;
        }
        do
        {
            rc = Reader(f, a, &n);
            first += 1;
            if (rc != OK)
                break;
            else
            {
                for (size_t i = 0; i < n; i++)
                    printf("%d ", a[i]);
                if (n != 0)
                    printf("\n");
            }
        } while (feof(f) == 0);
        fclose(f);
    }
    else
    {
        printf("Where is my file, Billy?\n");
        rc = WHERE;
    }
    if (first == 1 && rc == OK && n == 0)
        rc = EMPTY;
    return rc;
}
