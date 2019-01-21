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

#define _(d)    ((d)-'0')

static char const limits[][3] = {
    /* 0, 1 */
    {0, 0}, {0, 0},
    /* 2, 3 */
    {'a', 'c', 3}, {'d', 'f', 3},
    /* 4, 5, 6 */
    {'g', 'i', 3}, {'j', 'l', 3}, {'m', 'o', 3},
    /* 7, 8, 9 */
    {'p', 's', 4}, {'t', 'v', 3}, {'w', 'z', 4},
};

static void *new(void *b, size_t size)
{
    void *ret = realloc(b, size);
    if (!ret) exit(-1);
    return ret;
}

static void walk(char *digits, int si, char *stack, char **ret, int *idx)
{
    if ('\0' == digits[si]) {
        ret[(*idx)++] = strdup(stack);
        return;
    }

    for (char c = limits[_(digits[si])][0]; c <= limits[_(digits[si])][1]; c++) {
        stack[si] = c;
        walk(digits, si+1, stack, ret, idx);
    }
}

/* TODO implement by the stack */
char **letterCombinations(char *digits, int *returnSize)
{
    if (!digits || '\0' == *digits || !returnSize)
        return NULL;

    int rs = 1;
    int i;
    for (i = 0; '\0' != digits[i]; i++)
        rs *= limits[_(digits[i])][2];

    char *stack = new(NULL, (i+1) * sizeof(stack[0]));
    stack[i] = '\0';
    char **ret = new(NULL, rs * sizeof(ret[0]));
    *returnSize = 0;
    walk(digits, 0, stack, ret, returnSize);
    free(stack);

    return ret;
}

int main(int argc, char **argv)
{
#define DIGITS_LEN_MAX  (1024)
    char digits[DIGITS_LEN_MAX];

    while (1 == scanf("%s", digits)) {
        int ret_size;
        char **ret = letterCombinations(digits, &ret_size);
        for (int i = 0; i < ret_size; i++) {
            printf("%s\n", ret[i]);
            free(ret[i]);
        }
        free(ret);
    }

    return 0;
}
