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

#define TREE_DEPTH_MAX  (20)
#define HOUSE_MAX       (1<<TREE_DEPTH_MAX)

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

typedef struct cache_t {
    int rob[2];
    struct TreeNode *node;
    char visited[2];
} cache_t;
#define STEAL   1
#define UNSTEAL 0

/* default initializes @cache 0 */
static cache_t caches[HOUSE_MAX];
static cache_t *gain_slot(struct TreeNode *node)
{
#define next_slot(x)    ((x+1)%HOUSE_MAX)
#define prev_slot(x)    ((x+HOUSE_MAX-1)%HOUSE_MAX)
    unsigned int hash = (unsigned int)node % HOUSE_MAX;
    unsigned int end = prev_slot(hash);
    for (; hash != end; hash = next_slot(hash)) {
        if (node == caches[hash].node)
            return caches+hash;
        if (NULL == caches[hash].node) {
            caches[hash].node = node;
            return caches+hash;
        }
    }

    /* FULL */
    return NULL;
#undef next_slot
#undef prev_slot
}


static int _rob(struct TreeNode *tree, int steal)
{
    if (!tree) return 0;
    /* have cache or visited */
    cache_t *cache = gain_slot(tree);
    /* @caches is too small */
    if (!cache) return 0;

    if (cache->visited[steal])
        return cache->rob[steal];

    int l0 = _rob(tree->left,  UNSTEAL);
    int r0 = _rob(tree->right, UNSTEAL);
    if (steal) {
        int val = tree->val + l0 + r0;
        caches->visited[STEAL] = 1;
        caches->rob[STEAL] = val;
        return val;
    }

    int l1 = _rob(tree->left,  STEAL);
    int r1 = _rob(tree->right, STEAL);

    int val = MAX(l0, l1) + MAX(r0, r1);

    caches->visited[UNSTEAL] = 1;
    caches->rob[UNSTEAL] = val;

    return val;
}

/* O(2^n) Bad:( */
int rob(struct TreeNode *root)
{
    memset(caches, 0, HOUSE_MAX * sizeof(cache_t));
    return MAX(_rob(root, UNSTEAL), _rob(root, STEAL));
}
