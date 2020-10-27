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

static unsigned int xor(unsigned int a_, int b_, int *sign, int n)
{
    unsigned int num[128];
    int idx = 0;

    *sign += (b_ < 0);
    *sign %= n;

    unsigned int a = a_;
    unsigned int b = (b_ < 0)? (unsigned int)~b_+1: b_;

    for (; a && b; a /= n, b /= n, idx++)
        num[idx] = (a%n + b%n)%n;
    for (; a; a /= n, idx++)
        num[idx] = a%n;
    for (; b; b /= n, idx++)
        num[idx] = b%n;

    unsigned int ret = 0;
    while (idx-- > 0)
        ret = ret*n + num[idx];

    return ret;
}

int singleNumber(int *nums, int numsSize)
{
    unsigned int ret = 0;
    int sign = 0;
    for (int i = 0; i < numsSize; i++) {
        ret = xor(ret, nums[i], &sign, 3);
    }
    printf("%u %d\n", ret, (sign == 1)? (int)~ret+1: ret);

    return (sign == 1)? (int)(~ret+1): (int)ret;
}

int main(int argc, char **argv)
{
    for (int n; scanf("%d", &n) != EOF && n > 0; ) {
        int arr[n];
        for (int i = 0; i < n; ++i)
            scanf("%d", arr+i);
        printf("%d\n", singleNumber(arr, n));
    }
    return 0;
}

