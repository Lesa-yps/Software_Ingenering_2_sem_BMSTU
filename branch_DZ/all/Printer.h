#ifndef PRINTER_H
#define PRINTER_H

#include <stdio.h>
#include <stddef.h>

#include "const.h"

/**
 * @brief Writes an array of integers to a file.
 *
 * @param f A FILE pointer to the output file.
 * @param a An array of integers to be written to the file.
 * @param n The number of elements in the array.
 */

void Printer(FILE *f, int a[], size_t n);

#endif // PRINTER_H
