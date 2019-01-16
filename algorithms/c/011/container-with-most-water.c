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

/* brute force + optimization */
int maxArea(int *height, int heightSize)
{
    if (heightSize < 2) return 0;
    int maxarea = MIN(height[0], height[1]);
    for (int i = 2; i < heightSize; i++) {
        if (0 == height[i]) continue;
        int minwidth = maxarea/height[i];
        for (int j = 0; i-j >= minwidth; j++) {
            int area = MIN(height[i], height[j]) * (i-j);
            if (area > maxarea) {
                maxarea = area;
                minwidth = maxarea/height[i];
            }
        }
    }
    return maxarea;
}

int maxArea2(int *height, int heightSize)
{
    int maxarea = 0;
    for (int *end = height+heightSize-1; height < end; ) {
        maxarea = MAX(maxarea, (end-height)*MIN(*height, *end));
        if (*height < *end)
            height++;
        else
            end--;
    }

    return maxarea;
}

int main(int argc, char **argv)
{
#define ARR_SIZE_MAX    (1024)
    int n;
    int height[ARR_SIZE_MAX];
    while (1 == scanf("%d", &n)) {
        for (int i = 0; i < n; i++)
            scanf("%d", height+i);
        printf("%d %d\n", maxArea(height, n), maxArea2(height, n));
    }

    return 0;
}

