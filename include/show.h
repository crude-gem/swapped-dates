#ifndef SHOW_H
#define SHOW_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// p : one dimensional array of data
// colhead : header that appears at the top of the 2D array/table
// rowhead : header that appears at the left side of the 2D array/table
// size1d : size of the 2D array in one dimension; e.g., 12 in 12x12
bool show1das2d(const int *p, const int *colhead, const int *rowhead,
                const size_t size1d);

bool show1d(const int *p, const size_t size);

#endif // !SHOW_H
