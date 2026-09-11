#include "show.h"
#include "util.h"
#include "config.h"

static void _headerspace()
{
    char headspace[HEADER_SPACING+1] = {0};
    memset(headspace, ' ', HEADER_SPACING);
    printf("%s", headspace);
}

static void _header(const int *p, const size_t size)
{
    _headerspace();
    for (size_t i = 0; i < size; i++) {
        printf("%" STRINGIFY(DIGIT_WIDTH) "d ", p[i]);
    }
}

static void _rulespace()
{
    char rulespace[RULE_SPACING+1] = {0};
    memset(rulespace, ' ', RULE_SPACING);
    printf("\n%s", rulespace);
}

static void _rule(const size_t size)
{
    const int rulesz = size*RULE_SIZE;
    char *rule = malloc(rulesz+1); // dynamic alloc cuz of "size"
    rule[rulesz] = '\0';
    memset(rule, '-', rulesz);
    printf("%s\n", rule);
    free(rule);
}

static void _horizrule(const size_t size)
{
    _rulespace();
    _rule(size);
}

static void _showcolhead(const int *p, const size_t size)
{

    _header(p, size);
    _horizrule(size);
}

static void _showrows(const int *p, const int *rowhead, const size_t size)
{
    for (size_t i = 0; i < size; i++) {
        printf("%3d | ", rowhead[i]);
        for (size_t j = 0; j < size; j++) {
            printf("%" STRINGIFY(DIGIT_WIDTH) "d ", p[i*size+j]);
        }
        printf("\n");
    }
}

// p : one dimensional array of data
// colhead : header that appears at the top of the 2D array/table
// rowhead : header that appears at the left side of the 2D array/table
// size1d : size of the 2D array in one dimension; e.g., 12 in 12x12
bool show1das2d(const int *p, const int *colhead, const int *rowhead,
                const size_t size1d)
{
    if (!p || size1d <= 0) return false;
    _showcolhead(colhead, size1d);
    _showrows(p, rowhead, size1d);
    return true;
}

bool show1d(const int *p, const size_t size)
{
    if (!p || size <= 0) return false;
    printf("{");
    for (size_t i = 0; i < size-1; i++) {
        printf("%d, ", p[i]);
    }
    printf("%d}", p[size-1]);
    printf("\n");
    return true;
}
