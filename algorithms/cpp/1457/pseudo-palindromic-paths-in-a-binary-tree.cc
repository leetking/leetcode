#include <algorithm>
#include <map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        int evens = 0xfff;
        return dfs(root, evens, 0);
    }
private:
    int dfs(TreeNode* root, int evens, int odd_cnt) {
        if (!root)
            return 0;
        evens ^= (1<<root->val);
        if (evens & (1<<root->val))
            --odd_cnt;
        else
            ++odd_cnt;
        if (!root->left && !root->right) {
            evens ^= (1<<root->val);
            return (odd_cnt <= 1);
        }
        int ret = 0;
        ret += dfs(root->left, evens, odd_cnt);
        ret += dfs(root->right, evens, odd_cnt);
        evens ^= (1<<root->val);
        return ret;
    }
};
