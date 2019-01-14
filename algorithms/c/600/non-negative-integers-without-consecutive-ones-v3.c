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

static int _caches[33];
int *caches = _caches+1;

/* num <= 10^9 < 0xffffffff */
static int _findIntegers(int num, int start_bit)
{
    if (start_bit == -1) return 1;
    if (start_bit == 0) return (num&1)+1;

    /* 2^x => caches[x] */
    static int _TAB[] = {
        1,
        2,       3,      5,      8,       13,
        21,      34,     55,     89,      144,
        233,     377,    610,    987,     1597,
        2584,    4181,   6765,   10946,   17711,
        28657,   46368,  75025,  121393,  196418,
        317811,  514229, 832040, 1346269, 2178309,
        3524578,
    };
    int const *TAB = _TAB+1;

    int pick_bit1 = 1<<start_bit;
    int pick_bit2 = 1<<(start_bit-1);

    if (-1 != caches[start_bit])
        return caches[start_bit];

    if (num & pick_bit1) {
        /* 1xxx + 01111 */

        /** non optimization version
         * return _findIntegers(((num&pick_bit2)? 0xffffffff: num) &mask2, start_bit-2)
         *  + _findIntegers(0xffffffff&mask1, start_bit-1);
         */
        if (num & pick_bit2) {
            return TAB[start_bit-1] + TAB[start_bit-2];
        } else {
            if (-1 == caches[start_bit-2])
                caches[start_bit-2] = _findIntegers(num, start_bit-2);
            return TAB[start_bit-1] + caches[start_bit-2];
        }
    }

    return (caches[start_bit] = _findIntegers(num, start_bit-1));
}

int findIntegers(int num)
{
    memset(_caches, 0xff, 33 * sizeof(int));
    return _findIntegers(num, 31);
}

int main(int argc, char **argv)
{
    int num;
    while (1 == scanf("%d", &num)) {
        printf("%d\n", findIntegers(num));
    }
    return 0;
}
