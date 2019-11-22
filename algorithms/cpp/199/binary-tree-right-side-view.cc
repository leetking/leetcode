#include <cstdio>
#include <climits>
#include <cctype>
#include <cmath>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ARR_SIZE(x)     ((int)sizeof(x)/sizeof(x[0]))

#ifndef NDEBUG      /* fllow the macor `NDEBUG` from assert.h */
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ret;
        queue<TreeNode*> queue;
        TreeNode *node;
        if (!root) return {};

        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            int side;
            for (int i = 0; i < size; i++) {
                node = queue.front(); queue.pop();
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
                side = node->val;
            }
            ret.push_back(side);
        }
        return ret;
    }
};
