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

int myAtoi(char const *str)
{
    int state = 0;
    int neg = 0;
    double ret = 0;
    for (;; ++str) {
        switch (state) {
        case 0:
            if ('\0' == *str) goto finish;

            if ('-' == *str) {
                state = 1;
                neg = 1;
            } else if ('+' == *str) {
                state = 1;
            } else if (isdigit(*str)) {
                state = 1;
                ret = 10*ret + *str-'0';
            } else if (!isspace(*str)) {
                return 0;
            }
            break;
        case 1:
            if (isdigit(*str)) {
                ret = 10*ret + *str-'0';
                /* overflow */
                if (!neg && ret > (double)INT_MAX)
                    return INT_MAX;
                if (neg && -ret < (double)INT_MIN)
                    return INT_MIN;
            } else {
                goto finish;
            }
            break;
        }
    }

finish:
    return neg? (int)(-ret): (int)ret;
}

int main(int argc, char **argv)
{
    char *strs[] = {
        "       -42",       /* -42 */
        "4103 the word",    /* 4103 */
        "words and 942",    /* 0 */
        "0",                /* 0 */
        "10",               /* 10 */
        "-10",              /* -10 */
        "-00001",           /* -1 */
        "2147483647",       /* 2147483647 */
        "2147483648",       /* 2147483647 */
        "-2147483648",      /* -2147483648 */
        "-2147483649",      /* -2147483648 */
        "-1010023630o4",
        NULL,
    };
    for (char **p = strs; *p; p++)
        printf("%d\n", myAtoi(*p));

    return 0;
}
