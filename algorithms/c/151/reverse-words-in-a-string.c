#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *reverseWords(char *s)
{
    if (!s) return NULL;

    int len = strlen(s);
    char *tmp = malloc(len + 1);
    char *str = tmp;
    char *end;
    int state = 0;
    for (char *e = s + len - 1; -1 != state; --e) {
        switch (state) {
        case 0: /* space */
            if (e < s) {
                state = -1;
                break;
            }
            if (!isspace(*e)) {
                end = e;
                state = 1;
            }
            break;

        case 1: /* string */
            if (e < s || isspace(*e)) {
                strncpy(str, e+1, end - e);
                str += end - e;
                *str++ = ' ';
                state = 0;
                if (e < s)
                    state = -1;
            }
            break;
        }
    }
    str[-1] = '\0'; /* remove ' ' */
    strcpy(s, tmp);
    free(tmp);
    return s;
}

char *reverse(char *s, char *e, char *to)
{
    char t;
    for (; s <= e && to <= e; ++to, --e) {
        t = *to;
        *to = *e;
        *e = t;
    }
    return to + (e-s + 1);
}

char *reverseWords2(char *s)
{
    if (!s) return NULL;
    char *ret = s;
    char *idx = s;

    char *start;
    do {
        while (isspace(*s))
            ++s;
        start = s;
        while ('\0' != *s && !isspace(*s))
            ++s;
        if (start <= s-1) {
            idx = reverse(start, s-1, idx);
            if ('\0' != *idx)
                *idx++ = ' ';
        }
    } while ('\0' != *s);
    if (' ' == idx[-1])
        *(--idx) = '\0';     /* remove ' ' */
    reverse(ret, idx-1, ret);

    return ret;
}


int main()
{
    char str[] = "a good     example";
    printf("%s\n", reverseWords2(str));
    return 0;
}
