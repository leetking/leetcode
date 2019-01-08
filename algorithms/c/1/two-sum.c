#include <stdio.h>
#include <stdlib.h>

typedef struct pairs {
    int idx, num;
} pairs_t;

static int pairs_cmp(void const *a, void const *b)
{
    return ((pairs_t*)a)->num - ((pairs_t*)b)->num;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
    if (!nums || numsSize < 0) return NULL;

    pairs_t *list;
    int *ret = NULL;
    list = malloc(numsSize * sizeof(pairs_t));
    if (!list) return NULL;
    ret = malloc(sizeof(int)*2);
    if (!ret) goto quit;
    ret[0] = ret[1] = -1;

    for (int i = 0; i < numsSize; i++) {
        list[i].idx = i;
        list[i].num = nums[i];
    }
    qsort(list, numsSize, sizeof(pairs_t), pairs_cmp);
    int s, e;
    for (s = 0, e = numsSize-1; s >= 0 && s < e && e < numsSize; ) {
        int sum = list[s].num + list[e].num;
        if (sum == target) {
            ret[0] = list[s].idx;
            ret[1] = list[e].idx;
            break;
        } else if (sum > target) {
            e--;
        } else {    /* sum < target */
            s++;
        }
    }

quit:
    free(list);
    return ret;
}

int main()
{
    int target;
    int n;
    if (2 != scanf("%d %d", &target, &n)) return 1;
    int *nums = malloc(sizeof(int) * n);
    if (!nums) return 2;

    for (int i = 0; i < n; i++) {
        if (1 != scanf("%d", nums+i)) {
            free(nums);
            return 3;
        }
    }

    int *ret = twoSum(nums, n, target);
    printf("%d %d\n", ret[0], ret[1]);

    free(nums);
    free(ret);

    return 0;
}
