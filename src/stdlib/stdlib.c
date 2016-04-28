#include <stdint.h>
#include <stdlib.h>

#include "../ctype.c"

#include "abs.c"
#include "div.c"
#include "exit.c"
#include "rand.c"
#include "strto.c"

#undef atof
double atof(const char *s)
{
    return strtod(s, (char **)NULL);
}


void *bsearch(const void *key, const void *base,
        size_t nmemb, size_t size,
        int (*compar)(const void *, const void *))
{
    size_t lo = 0, hi = nmemb;
    while (lo <= hi) {
        size_t mid = nmemb / 2;
        uintptr_t center = (uintptr_t) base + mid * size;
        int ans = compar(key, (void*)center);

        if (ans < 0) {
            hi = lo + (nmemb = mid) - 1;
        } else if (ans > 0) {
            base = (void*)(center + (lo = size));
            nmemb -= mid;
        } else { /* ans == 0 */
            return (void*)center;
        }
    }
    return NULL;
}

static void memswap(void *a, void *b, size_t size)
{
    /* swap a char at a time */
    char *p1 = a, *p2 = b;
    char buf;
    size_t i;

    if (a == b) return; /* this case is pretty common */

    for (i = 0; i < size; i++) {
        buf = p1[i];
        p1[i] = p2[i];
        p2[i] = buf;
    }
}

static size_t partition(void *base, size_t nmemb,
        size_t size,
        int (*compar)(const void *, const void *))
{
    /* Using Lomuto's Partitioning Scheme as described in
     * Introduction to Algorithms by Cormen et al.
     */
    void *elem = base, *pivot = (void *)((uintptr_t)base + (nmemb - 1) * size);
    size_t i /* index of partition divider */, j /* looping variable */;
    for (i = j = 0; j < nmemb - 1; j++, elem = (void*)((uintptr_t)elem + size))
        if (compar(elem, pivot) < 0)
            memswap((void*)((uintptr_t)base + size * i++), elem, size);
    memswap((void*)((uintptr_t)base + size * i), pivot, size);
    return i;
}

void qsort(void *base, size_t nmemb, size_t size,
        int (*compar)(const void *, const void *))
{
    if (nmemb > 1) {
        size_t pivot = partition(base, nmemb, size, compar);
        qsort(base, pivot, size, compar);
        qsort((void *)((uintptr_t)base + size * (pivot + 1)),
                nmemb - (pivot + 1), size, compar);
    }
}

