#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <stdarg.h>

#define ARR_SIZE(x)     ((int)(sizeof(x)/sizeof(x[0])))

#define MAX(x, y)   ((x)>(y)? (x): (y))
#define MIN(x, y)   ((x)<(y)? (x): (y))
#define ABS(x)      ((x)<0?  -(x): (x))

#ifdef DEBUG
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

void solve(int const *arr, int len, int *x, int *y)
{
    int bits = 0;
    for (int i = 1; i <= len-2; ++i)
        bits ^= i;
    for (int i = 0; i < len; ++i)
        bits ^= arr[i];
    int divided_bit = bits & ~(bits-1);

    *x = *y = 0;
    for (int i = 1; i <= len-2; ++i) {
        if (i & divided_bit)
            *x ^= i;
        else
            *y ^= i;
    }
    for (int i = 0; i < len; ++i) {
        if (arr[i] & divided_bit)
            *x ^= arr[i];
        else
            *y ^= arr[i];
    }
}

int main(int argc, char **argv)
{
    int arr[] = {
        1, 1, 2, 3, 4, 5, 5
    };
    int x, y;
    solve(arr, ARR_SIZE(arr), &x, &y);
    printf("%d %d\n", x, y);
    /* out> 1 5 */
    return 0;
}

