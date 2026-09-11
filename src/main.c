#include "main.h"
#include "util.h"
#include "swapdate.h"
#include "show.h"

int main(void)
{
    // struct arena *a = anew(sizeof(int)*256);

    int days_and_months[DM_SIZE] = {0};
    if (!seqfill(days_and_months, DM_SIZE)) return 1;

    int differences[DM_SIZE * DM_SIZE] = {0};
    // int differences_2d[DM_SIZE][DM_SIZE] = {0};

    if (!calc(days_and_months, differences, DM_SIZE)) return 1;

    if (!show1das2d(differences, days_and_months, days_and_months, DM_SIZE))
        return 1;

    // int *sums;
    // size_t sumssz;
    // if (!runningsum(a, &sums, &sumssz)) return 1;
    // if (!show1d(sums, sumssz)) return 1;

    // adelete(a);
	return 0;
}
