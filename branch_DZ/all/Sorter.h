#ifndef SORTER_H
#define SORTER_H

#include <stddef.h>

#include "Sort_min.h"
#include "Sort_max.h"

#include "const.h"

/**
 * @brief Sorts an array of integers even ones in ascending
 *  order followed by odd ones in descending order.
 *
 * @param a An array of integers to be sorted.
 * @param n The number of elements in the array.
 */

void Sorter(int a[], size_t n);

#endif // SORTER_H
