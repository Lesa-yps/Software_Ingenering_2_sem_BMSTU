#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stddef.h>
#include <ctype.h>

#include "const.h"

int Reader(FILE *f, int a[], size_t *n);

#endif // READER_H
