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

static int string_equal(char *s1, int o1, char *s2, int o2, int len)
{
    int i;
    for (i = 0; i < len && s1[o1] == s2[o2]; i++) {
        o1 = (o1+1)%len;
        o2 = (o2+1)%len;

    }
    return (i == len);
}

/**
 * NOTE because the length of string is at most 100
 * the length is so small that there is no reason to
 * strive an optimization
 * BUT, TODO I deeply believe an O(n) algorithm exsiting.
 */

/* O(n^2) */
int rotateString(char *A, char *B)
{
    int lenA = strlen(A), lenB = strlen(B);
    if (lenA != lenB) return 0;

    /* A and B both is empty string */
    if (0 == lenA) return 1;

    /* assume lenA == lenB */
    for (int i = 0; i < lenB; i++) {
        if (string_equal(A, 0, B, i, lenA))
            return 1;
    }

    return 0;
}

int main(int argc, char **argv)
{
#define STR_MAX (100+1)
    char empty[] = "";
    char s1[STR_MAX], s2[STR_MAX];
    while (2 == scanf("%s %s", s1, s2)) {
        printf("%s\n", rotateString(s1, s2)? "True": "False");
    }
    printf("%s\n", rotateString(empty, empty)? "True": "False");

    return 0;
}
