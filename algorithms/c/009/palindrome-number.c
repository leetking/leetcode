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

int isPalindrome(int x)
{
    if (x < 0) return 0;

    int orig = x;
    int reverse = 0;
    while (x) {
        if ((reverse > INT_MAX/10) || (reverse < INT_MIN/10))
            return 0;
        reverse *= 10;
        reverse += (x%10);
        x /= 10;
    }

    return (reverse == orig);
}

int main(int argc, char **argv)
{
    int num;
    while (1 == scanf("%d", &num)) {
        printf("%s\n", isPalindrome(num)? "True": "False");
    }
    return 0;
}
