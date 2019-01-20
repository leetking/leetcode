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
#define ABS(x)      ((x)<0? -(x): (x))

#ifdef DEBUG
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

static int int_cmp(void const *a, void const *b)
{
    return *(int*)a-*(int*)b;
}

int threeSumClosest(int *nums, int numsSize, int target)
{
    /* erroneous input */
    if (!nums || numsSize < 3) return target;

    qsort(nums, numsSize, sizeof(nums[0]), int_cmp);

    int ret = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize; i++) {
        int x = target - nums[i];
        for (int l = i+1, r = numsSize-1; l < r; ) {
            int s = nums[l] + nums[r];
            if (ABS(x-s) < ABS(ret - target))
                ret = nums[i]+s;
            if (x < s)
                r--;
            else if (x > s)
                l++;
            else
                return target;
        }
    }

    return ret;
}

int main(int argc, char **argv)
{
#define NUM_CNT_MAX (1024)
    int n, x;
    int nums[NUM_CNT_MAX];

    while (1 == scanf("%d", &n)) {
        for (int i = 0; i < n; i++)
            scanf("%d", nums+i);
        scanf("%d", &x);
        printf("%d\n", threeSumClosest(nums, n, x));
    }
    return 0;
}

