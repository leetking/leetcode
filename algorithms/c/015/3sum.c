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

void *new(void *base, size_t size)
{
    void *ret = realloc(base, size);
    if (!ret) exit(1);    /* alloc error */
    return ret;
}

#define HASH_SIZE_MAX   (10007)
typedef struct hash_t {
    int num;
    int cnt;
} hash_t;
static hash_t hashs[HASH_SIZE_MAX];
#define next_slot(k)    ((k+1)%HASH_SIZE_MAX)
#define prev_slot(k)    ((k-1+HASH_SIZE_MAX)%HASH_SIZE_MAX)

static int hash_put(int num)
{
    unsigned int key = (unsigned int)num % HASH_SIZE_MAX;
    unsigned int end = prev_slot(key);
    for (; key != end; key = next_slot(key)) {
        if (hashs[key].cnt == -1 || hashs[key].num == num) {
            hashs[key].num = num;
            hashs[key].cnt += (hashs[key].cnt == -1)? 2: 1;
            return hashs[key].cnt;
        }
    }

    /* The hash table is full! */
    return -1;
}

static int hash_have(int num, int cnt)
{
    unsigned int key = (unsigned int)num % HASH_SIZE_MAX;
    unsigned int end = prev_slot(key);
    for (; key != end; key = next_slot(key)) {
        if (hashs[key].cnt == -1)
            return 0;
        if (hashs[key].num == num)
            return (cnt <= hashs[key].cnt);
    }

    return 0;
}

static int int_cmp(void const *a, void const *b)
{
    return *(int*)a-*(int*)b;
}

static int ret_cmp(void const *_a, void const *_b)
{
    int **a = (int**)_a;
    int **b = (int**)_b;
    if ((*a)[0] != (*b)[0]) return (*a)[0] - (*b)[0];
    if ((*a)[1] != (*b)[1]) return (*a)[1] - (*b)[1];
    return (*a)[2] - (*b)[2];
}

static int **_threeSum(int *nums, int numSize, int *returnSize)
{
    int arr_n = 2;
    int **ret = new(NULL, arr_n * sizeof(ret[0]));
    int idx = 0;
    *returnSize = 0;

    for (int i = 0; i < numSize; i++)
        hash_put(nums[i]);
    qsort(nums, numSize, sizeof(nums[0]), int_cmp);
    int l = 0, r = numSize-1;
    for (l = 0; nums[l] < 0; l++) {
        if (l >= 1 && nums[l] == nums[l-1])
            continue;

        for (r = numSize-1; nums[r] > 0; r--) {
            if (r <= numSize-2 && nums[r] == nums[r+1])
                continue;

            int need = -(nums[l] + nums[r]);
            int cnt = 1 + (need == nums[l]) + (need == nums[r]);
            if (nums[l] <= need && need <= nums[r] && hash_have(need, cnt)) {
                if (idx >= arr_n) {
                    arr_n = 1.618*(arr_n+1);
                    ret = new(ret, arr_n * sizeof(ret[0]));
                }
                ret[idx] = new(NULL, 3 * sizeof(int));
                ret[idx][0] = nums[l];
                ret[idx][1] = need;
                ret[idx][2] = nums[r];
                idx++;
            }
        }
    }

    /* 0 + 0 + 0 == 0 */
    while (nums[l] < 0)
        l++;
    while (nums[r] > 0)
        r--;
    if (r-l >= 2) {
        if (idx >= arr_n) {
            arr_n++;
            ret = new(ret, arr_n * sizeof(ret[0]));
        }
        ret[idx] = new(NULL, 3 * sizeof(int));
        ret[idx][0] = ret[idx][1] = ret[idx][2] = 0;
        idx++;
    }

    qsort(ret, idx, sizeof(ret[0]), ret_cmp);

    *returnSize = idx;
    return (int**)ret;
}

int **threeSum(int *nums, int numSize, int *returnSize)
{
    if (!nums || numSize < 0 || !returnSize) return NULL;
    memset(hashs, 0xff, HASH_SIZE_MAX * sizeof(hash_t));
    return _threeSum(nums, numSize, returnSize);
}


int main(int argc, char **argv)
{
#define NUM_CNT_MAX (1024)
    int n;
    int nums[NUM_CNT_MAX];
    int **ret;
    int ret_size;

    while (1 == scanf("%d", &n)) {
        for (int i = 0; i < n; i++)
            scanf("%d", nums+i);
        ret = threeSum(nums, n, &ret_size);
        for (int i = 0; i < ret_size; i++) {
            printf("%d+%d+%d=(%d)\n", ret[i][0], ret[i][1], ret[i][2],
                    ret[i][0]+ret[i][1]+ret[i][2]);
            /* free */
            free(ret[i]);
        }
        free(ret);
        printf("===\n");
    }

    return 0;
}
