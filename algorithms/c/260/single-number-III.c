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

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    int *ret = malloc(2 * sizeof(int));
    ret[0] = ret[1] = 0;
    *returnSize = 2;
    int bits = 0;
    for (int i = 0; i < numsSize; ++i)
        bits ^= nums[i];
    int divided_bit = bits & ~(bits-1);
    for (int i = 0; i < numsSize; ++i) {
        if (divided_bit & nums[i])
            ret[0] ^= nums[i];
        else
            ret[1] ^= nums[i];
    }

    return ret;
}

int main(int argc, char **argv)
{
    for (int n; scanf("%d", &n) != EOF && n > 0; ) {
        int arr[n];
        for (int i = 0; i < n; ++i)
            scanf("%d", arr+i);
        int size;
        int *ret = singleNumber(arr, n, &size);
        printf("%d %d\n", ret[0], ret[1]);
        free(ret);
    }
    return 0;
}

