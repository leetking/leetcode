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

#define TREE_DEPTH_MAX  (19)
#define HOUSE_MAX       ((1<<TREE_DEPTH_MAX)-1)

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

typedef struct cache_t {
    int val;
    struct TreeNode *node;
    char visited;
} cache_t;

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

static int _rob(struct TreeNode *root)
{
    if (!root) return 0;
    cache_t *cache = gain_slot(root);
    if (cache->visited)
        return cache->val;

    int val = 0;
    if (root->left)
        val += _rob(root->left->left) + _rob(root->left->right);
    if (root->right)
        val += _rob(root->right->left) + _rob(root->right->right);

    val = MAX(root->val + val, _rob(root->left) + _rob(root->right));
    cache->visited = 1;
    cache->val = val;

    return val;
}

int rob(struct TreeNode *root)
{
    memset(caches, 0, HOUSE_MAX * sizeof(cache_t));
    return _rob(root);
}
