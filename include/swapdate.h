#ifndef SWAPDATE_H
#define SWAPDATE_H

#include "arena.h"

#include <stdbool.h>
#include <stdlib.h>

#define NUM_OF_MONTHS 12

bool runningsum(struct arena *a, int **sumsout, size_t *sizeout);

int dayssincejan1incl(const int month, const int day);

int dayssincejan1excl(const int month, const int day);

int swapdiff(const int month, const int day);

bool calc(const int *in, int *out, const size_t size);

#endif // !SWAPDATE_H
