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
#define ABS(x)      ((x)<0?  -(x): (x))

#ifdef DEBUG
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

static void *new(void *b, size_t size)
{
    void *ret = realloc(b, size);
    if (!ret) exit(-1);
    return ret;
}

static int int_cmp(void const *a, void const *b)
{
    return *(int*)a-*(int*)b;
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize)
{
    qsort(nums, numsSize, sizeof(nums[0]), int_cmp);

    int **ret = new(NULL, 2 * 4*sizeof(int));
    int alc_size = 2;
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        while (i >= 1 && nums[i] == nums[i-1])
            i++;

        for (int j = i+1; j < numsSize; j++) {
            while (j >= i+2 && nums[j] == nums[j-1])
                j++;

            int x = target - nums[i] - nums[j];
            for (int l = j+1, r = numsSize-1; l < r; ) {
                int s = nums[l] + nums[r];
                if (x > s) {
                    l++;
                } else if (x < s) {
                    r--;
                } else {
                    if (*returnSize >= alc_size) {
                        alc_size = (int)(1.618*alc_size);
                        ret = new(ret, alc_size * sizeof(ret[0]));
                    }
                    ret[*returnSize] = new(NULL, 4*sizeof(int));
                    ret[*returnSize][0] = nums[i];
                    ret[*returnSize][1] = nums[j];
                    ret[*returnSize][2] = nums[l];
                    ret[*returnSize][3] = nums[r];
                    (*returnSize)++;

                    do {
                        l++;
                    } while (l < r && nums[l] == nums[l-1]);

                    do {
                        r--;
                    } while (l < r && nums[r] == nums[r+1]);
                }
            }
        }
    }

    return ret;
}

int main(int argc, char **argv)
{
#define NUM_MAX (1024)
    int n, x;
    int nums[NUM_MAX];
    while (1 == scanf("%d", &n)) {
        for (int i = 0; i < n; i++)
            scanf("%d", nums+i);
        scanf("%d", &x);

        int ret_size;
        int **ret = fourSum(nums, n, x, &ret_size);
        printf("%d\n", ret_size);
        for (int i = 0; i < ret_size; i++) {
            printf("%d+%d+%d+%d=(%d)\n",
                    ret[i][0], ret[i][1], ret[i][2], ret[i][3],
                    ret[i][0] + ret[i][1] + ret[i][2] + ret[i][3]);
            free(ret[i]);
        }
        free(ret);
        printf("\n");
    }
    return 0;
}
