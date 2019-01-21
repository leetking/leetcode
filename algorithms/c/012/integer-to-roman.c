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

#define ROMAN_MAX       3999
#define ROMAN_STR_MAX   sizeof("MMMDCCCLXXXVIII")

char *intToRoman(int num)
{
    static char ret[ROMAN_STR_MAX] = "";
    int idx = 0;

    if (num > ROMAN_MAX)
        return "";

    int units[] = {
        1, 5, 10, 50, 100, 500, 1000,
    };
    char coins[] = {
        'I', 'V', 'X', 'L', 'C', 'D', 'M',
    };

    for (int h = ARR_SIZE(units)-1; num; h--) {
        int d = num / units[h];

        if (0 == d) continue;

        /* 9xxx */
        if (h&1 && (num >= units[h]/5*9)) {
            ret[idx++] = coins[h-1];
            ret[idx++] = coins[h+1];
            num -= units[h]/5*9;
        } else {
            if (d < 4) {
                for (int i = 0; i < d; i++)
                    ret[idx++] = coins[h];
            } else if (d == 4) {
                ret[idx++] = coins[h];
                ret[idx++] = coins[h+1];
            }
            num %= units[h];
        }
    }

    ret[idx] = '\0';
    return ret;
}

int main(int argc, char **argv)
{
    int num;
    while (1 == scanf("%d", &num)) {
        printf("%d: %s\n", num, intToRoman(num));
    }

    return 0;
}

