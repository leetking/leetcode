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

/* like the max sum of subsequence */
int LengthOfLongestSubstring(char *s)
{
    if (!s) return 0;

    int last[0xff+1];
    /* set -1 */
    memset(last, 0xff, sizeof(last));

    int start = -1;
    int ret = 0;
    for (int i = 0; '\0' != s[i]; i++) {
        unsigned int c = s[i];
        int bang = last[c];
        int span = i - MAX(bang, start);
        ret = MAX(ret, span);
        last[c] = i;
        start = MAX(start, bang);
    }
    return ret;
}

#define STR_MAX (1024)
int main(int argc, char **argv)
{
    char str[STR_MAX];
    while (1 == scanf("%s", str)) {
        printf("%s:%d\n", str, LengthOfLongestSubstring(str));
    }
    return 0;
}

