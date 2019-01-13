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

/**
 * NOTE This is a classic problem,
 * https://en.wikipedia.org/wiki/Longest_palindromic_substring
 * There is a O(n) algorithm named Manacher's algorithm.
 * 1. LCM + check, time O(n^2) and space O(n)
 * 2. my solution shown as below
 * 3. Manacher's algorithm
 */

/* O(n^2) */
char *longestPalindrome(char *s)
{
    int len = 0;
    char *start = s;
    for (char *p = s; '\0' != *p; p++) {
        /* check the even-length substring */
        int i;
        for (i = 1; s <= (p-i) && '\0' != p[i-1] && p[-i] == p[i-1]; i++)
            ;
        if (2*i-2 > len) {
            start = p-i+1;
            len = 2*i-2;
        }

        /* check the odd-length substring that its center is p */
        for (i = 1; s <= (p-i) && '\0' != p[i] && p[-i] == p[i]; i++)
            ;
        if (2*i-1 > len) {
            start = p-i+1;
            len = 2*i-1;
        }
    }
    start[len] = '\0';
    return start;
}

int main(int argc, char **argv)
{
#define STR_MAX (1000+1)
    char str[STR_MAX];
    while (1 == scanf("%s", str)) {
        printf("%s\n", longestPalindrome(str));
    }
    char empty[] = "";
    printf("%s\n", longestPalindrome(empty));
    return 0;
}

