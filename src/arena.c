#include "arena.h"

static void * _atopptr(const struct arena *a)
{
    return ((unsigned char *)a->mem+a->top);
}

struct arena * anew(const size_t bytes)
{
    // if (bytes <= 0) return NULL;
    struct arena *a = malloc(sizeof(struct arena));
    // if (!a) return NULL;
    if (!a) {
        fprintf(stderr, "anew: Could not create arena struct\n");
        return NULL;
    }
    a->mem = malloc(bytes);
    // if (!a->mem) return NULL;
    if (!a->mem) {
        fprintf(stderr,
                "anew: Could not allocate initial memory inside arena\n");
        return NULL;
    }
    a->top = 0;
    a->szbytes = bytes;
    return a;
}

void adelete(struct arena *a)
{
    free(a->mem);
    free(a);
}

// NOTE: bytes := 0 is valid input
void * aalloc(struct arena *a, const size_t bytes)
{
    if (!a) {
        fprintf(stderr, "aalloc: Expected arena, got NULL\n");
        return NULL;
    }

    // if (!a->mem) return NULL;
    if (!a->mem) {
        fprintf(stderr, "aalloc: Arena memory not allocated\n");
        return NULL;
    }

    // if (bytes > a->szbytes - a->top) return NULL;
    if (bytes > a->szbytes - a->top) {
        fprintf(stderr, "aalloc: Not enough free memory in arena\n");
        return NULL;
    }
    void *newalloc = _atopptr(a);
    a->top += bytes;
    return newalloc;
}

bool afree(struct arena *a, const void *p)
{
    // `(unsigned char *)` to silence/fix warnings
    int diff = (int)((unsigned char *)(_atopptr(a)) - (unsigned char *)(p));
    if (diff < 0 || diff > (int)a->szbytes) {
        fprintf(stderr, "afree: Object not found in arena");
        return false;
    }
    a->top = diff;
    return true;
}
