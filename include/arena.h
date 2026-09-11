#ifndef ARENA_H
#define ARENA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct arena {
    void *mem;
    size_t szbytes;
    size_t top;
};

struct arena * anew(const size_t bytes);

void adelete(struct arena *a);

// NOTE: bytes := 0 is valid input
void * aalloc(struct arena *a, const size_t bytes);

bool afree(struct arena *a, const void *p);

#endif // !ARENA_H
