#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <stdarg.h>
#include <stdint.h>

#define ARR_SIZE(x)     ((int)(sizeof(x)/sizeof(x[0])))

#define MAX(x, y)   ((x)>(y)? (x): (y))
#define MIN(x, y)   ((x)<(y)? (x): (y))
#define ABS(x)      ((x)<0?  -(x): (x))

#ifdef DEBUG
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

int divide(int divided, int dividsor)
{
    int ans = 0;
    int sig = (divided<0) ^ (dividsor<0);
    divided = divided<0?   divided:  -divided;
    dividsor = dividsor<0? dividsor: -dividsor;
    /* NOTE INT32_MIN == -2^31, INT32_MAX == 2^31-1 from stdint.h */

    if (INT32_MIN == divided && -1 == dividsor)
        return sig? INT32_MIN: INT32_MAX;

    for (; divided <= dividsor; divided -= dividsor)
        ans++;

    return sig? -ans: ans;
}

int main(int argc, char **argv)
{
    int divided, dividsor;
    while (2 == scanf("%d %d", &divided, &dividsor)) {
        printf("%d\n", divide(divided, dividsor));
    }
    return 0;
}

