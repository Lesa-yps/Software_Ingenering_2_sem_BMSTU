#include <stdio.h>
#include <stddef.h>

#include "const.h"
#include "Reader.h"
#include "Sorter.h"
#include "Printer.h"

/**
 * @brief The main function of the program.
 *
 * @param argc The number of command-line arguments passed to the program.
 * @param argv An array of strings containing the command-line arguments passed to the program.
 *
 * @return An integer representing the exit status of the program.
 */

int main(int argc, char** argv)
{
    int a[MAX_LEN];
    size_t n;
    int x;
    int rc;
    FILE *f;
    FILE *f_out;
    if (argc < NUM_OUT_FILE + 1)
    {
        printf("Not enouth files\n");
        rc = NOT_ENOUTH_FILES;
    }
    else
    {
        f = fopen(argv[NUM_IN_FILE], "r");
        if (f == NULL)
        {
            printf("Input file is not exist\n");
            rc = EXIST1_ERROR;
        }
        else
        {
            f_out = fopen(argv[NUM_OUT_FILE], "w");
            if (f_out == NULL)
            {
                printf("Error with open output file\n");
                rc = EXIST2_ERROR;
            }
            else
            {
                fscanf(f, "%d", &x);
                if (feof(f) != 0)
                {
                    printf("File is empty\n");
                    rc = FILE_EMPTY;
                }
                else
                {
                    fseek(f, 0, SEEK_SET);
                    do
                    {
                        rc = Reader(f, a, &n);
                        if (rc != OK)
                        {
                            if (rc == NOT_INT && feof(f) == 0)
                                printf("Uncorrect file\n");
                            else if (rc == NUM_TOO_BIG)
                                printf("Too big numbers in file\n");
                            else if (rc == TOO_MUCH_NUMS)
                                printf("Too long strings in file\n");
                            else if (rc == ERR_N)
                                printf("Error with count of numbers\n");
                            break;
                        }
                        else
                        {
                            Sorter(a, n);
                            Printer(f_out, a, n);
                        }
                    } while (feof(f) == 0);
                fclose(f_out);
                }
            fclose(f);
            }
        }
    }
    return rc;
}
