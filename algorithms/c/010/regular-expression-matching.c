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

#define MAX_DEPTH   (1024)

static int _isMatch(char *s, char *p, int max_depth)
{
    if ('\0' == *s && '\0' == *p)
        return 1;

    /* the pattern is too complex */
    if (max_depth <= 0)
        return 0;

    while ('\0' != *p && '\0' != *s) {
        if ('*' == p[1] ) {
            /* zero repeat */
            if (_isMatch(s, p+2, max_depth-1))
                return 1;
            if ('.' == *p || *s == *p)
                s++;
            else
                p += 2;
        } else if ('.' == *p || *s == *p) {
            s++;
            p++;
        } else {
            return 0;
        }
    }

    /* skip the rest x* */
    for (; '\0' != *p && '*' == p[1]; p += 2)
        ;

    return ('\0' == *p && '\0' == *s);
}

#if 0
/* SOLUTION 1 */
bool isMatch(char* s, char* p) {
    for (char c = *p; c != 0; s++, c = *p) {
        // if next char in pattern is not *
        if (*(p+1) != '*')
            p++;
        // if we got an *, check if we can skip `.*` or `x*`
        else if (isMatch(s, p + 2))
            return true;

        // s ends or p and s differs
        if (*s == 0 || c != '.' && c != *s)
            return false;
    }
    return *s == 0;
}
#endif

/* SOLUTION 2: DP */
#if 0
dp[i][j] means s[0...i-1] matchs p[0...j-1]
#endif

int isMatch(char *s, char *p)
{
    return _isMatch(s, p, MAX_DEPTH);
}

int main(int argc, char **argv)
{
#define STR_MAX (1024)
    char str[STR_MAX], pattern[STR_MAX];
    while (2 == scanf("%s %s", str, pattern)) {
        printf("'%s'<->'%s': %s\n", str, pattern, isMatch(str, pattern)? "True": "False");
    }
    printf("'%s'<->'%s': %s\n", "", "c*c*", isMatch("", "c*c*")? "True": "False");
    return 0;
}

