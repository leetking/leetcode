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


struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};


void _rob(struct TreeNode *root, int *_in, int *_out)
{
    if (!root) {
        *_in = *_out = 0;
        return;
    }

    int lin, lout, rin, rout;
    _rob(root->left, &lin, &lout);
    _rob(root->right, &rin, &rout);

    *_in = root->val + lout + rout;
    *_out = MAX(lin, lout) + MAX(rin, rout);
}


int rob(struct TreeNode *root)
{
    int in, out;
    _rob(root, &in, &out);
    return MAX(in, out);
}
