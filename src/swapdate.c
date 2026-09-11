#include "swapdate.h"

bool runningsum(struct arena *a, int **sumsout, size_t *sizeout)
{
    static const int months[NUM_OF_MONTHS] =
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int *sums = aalloc(a, sizeof(*sums)*NUM_OF_MONTHS);
    if (!sums) return false;
    int sum = 0;
    for (size_t i = 0; i < NUM_OF_MONTHS; i++) {
        sum += months[i];
        sums[i] = sum;
    }
    *sumsout = sums;
    *sizeout = NUM_OF_MONTHS;
    return true;
}

int dayssincejan1incl(const int month, const int day)
{
    static const int monthssums[] =
        {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    return (monthssums[month-2] + day);
}

int dayssincejan1excl(const int month, const int day)
{
    return dayssincejan1incl(month, day) - 1;
}

int swapdiff(const int month, const int day)
{
    return abs(dayssincejan1excl(month, day)
            - dayssincejan1excl(day, month));
}

bool calc(const int *in, int *out, const size_t size)
{
    if (!in || !out || size <= 0) return false;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            out[i*size+j] = swapdiff(in[i], in[j]);
        }
    }
    return true;
}

