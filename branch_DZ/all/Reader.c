#include "Reader.h"

int Reader(FILE *f, int a[], size_t *n)
{
    int rc = OK;
    int flag = 0;
    int minus = 1;
    long int save;
    char c;
    *n = 0;
    while (fscanf(f, "%c", &c) == 1 && c != '\n')
    {
        if (feof(f))
            break;
        if (c >= '0' && c <= '9')
        {
            if ((*n) == MAX_LEN)
            {
                rc = TOO_MUCH_NUMS;
                break;
            }
            if (! flag)
            {
                flag = 1;
                a[*n] = 0;
            }
            save = ((long int)a[*n]) * 10 + c - '0';
            if (save > MAX_X)
            {
                rc = NUM_TOO_BIG;
                break;
            }
            a[*n] = save;
        }
        else if (c == '-' && flag == 0)
            minus = - minus;
        else if (isspace(c))
        {
            if (flag)
            {
                a[*n] *= minus;
                minus = 1;
                flag = 0;
                (*n)++;
            }
        }
        else if (c != '+')
        {
            rc = NOT_INT;
            break;
        }
    }
    if (flag)
    {
        a[*n] *= minus;
        (*n)++;
    }
    return rc;
}
