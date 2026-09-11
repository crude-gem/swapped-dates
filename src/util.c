#include "util.h"

bool seqfill(int *p, const size_t size)
{
    if (!p || size <= 0) return false;
    for (size_t i = 0; i < size; i++) {
        p[i] = i+1;
    }
    return true;
}

int abs(const int x)
{
    if (x < 0) return -x;
    return x;
}
