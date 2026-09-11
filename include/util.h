#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stdlib.h>

#define _STRINGIFY(x) #x
#define STRINGIFY(x) _STRINGIFY(x)

bool seqfill(int *p, const size_t size);

int abs(const int x);

#endif // !UTIL_H
