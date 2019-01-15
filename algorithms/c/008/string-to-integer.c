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

int myAtoi(char *str)
{
    enum {
        INIT,
        NUMBER,
    } state = INIT;

    int ret = 0;
    char sig = 0;
    for (; '\0' != *str; ++str) {
        switch (state) {
        case INIT:
            if ('+' == *str) {
                state = NUMBER;
                break;
            }
            if ('-' == *str) {
                sig = 1;
                state = NUMBER;
                break;
            }
            if (isspace(*str))
                break;
            if (isdigit(*str)) {
                ret = (*str-'0');
                state = NUMBER;
                break;
            }
            return 0;

        case NUMBER:
            if (isdigit(*str)) {
                int num = *str-'0';
                /* overflow */
                if (ret > INT_MAX/10 || (ret == INT_MAX/10 && num > INT_MAX%10))
                    return INT_MAX;
                if (ret < INT_MIN/10 || (ret == INT_MIN/10 && num > -(INT_MIN%10)))
                    return INT_MIN;
                ret *= 10;
                ret += (ret<0)? -num: num;
                /* append sig */
                if (sig) {
                    ret = -ret;
                    sig = (0==ret);
                }
                break;
            }

            /* meet non-digit number */
            return ret;

        default:
            return 0;
        }
    }

    return ret;
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

