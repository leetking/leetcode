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

char *convert(char *s, int numRows)
{
    if (numRows <= 1) return s;

    int len = strlen(s);
    char *tmp = malloc(len * sizeof(char));
    int cnt = 0;
    if (!tmp) return NULL;

    int gap = 2*numRows-2;
    for (int r = 0, step = gap; r < numRows; r++, step -= 2) {
        for (int i = r; i < len; i += gap) {
            tmp[cnt++] = s[i];
            int mid = i+step;
            if (i < mid && mid < i+gap && mid < len)
                tmp[cnt++] = s[mid];
        }
    }

    memcpy(s, tmp, len);
    free(tmp);
    return s;
}

int main(int argc, char **argv)
{
#define STR_MAX (1024)
    char str[STR_MAX];
    int rows;
    while (2 == scanf("%s %d", str, &rows)) {
        printf("%s\n", convert(str, rows));
    }
    return 0;
}

