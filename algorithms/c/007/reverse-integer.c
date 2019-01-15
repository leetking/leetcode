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

#ifdef DEBUG
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

#define INT32_MAX   (0x7fffffff)
#define INT32_MIN   ((int)0x80000000)

int reverse(int x)
{
    int ret = 0;

    while (x) {
        if ((ret > INT32_MAX/10) || (ret < INT32_MIN/10))
            return 0;
        ret *= 10;
        ret += (x%10);
        x /= 10;
    }

    return ret;
}

int main(int argc, char **argv)
{
    int nums[] = {
        0, 1, INT_MAX, INT_MIN,
        -2, 100, 2143443412,
        2143443412-1,
        2143443412+1,
        1534236469,
        -1234567890,
        -123,
    };

    printf("%d:%d\n", INT32_MAX/10, INT32_MIN/10);
    for (int i = 0; i < ARR_SIZE(nums); ++i) {
        printf("%d\t%d\n", nums[i], reverse(nums[i]));
    }

    return 0;
}

