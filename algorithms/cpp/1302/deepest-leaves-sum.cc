#include <queue>

using std::queue;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        max_deep = 0;
        sum = 0;
        helper(root, 0);
        return sum;
    }

private:
    int max_deep;
    int sum;
    void helper(TreeNode* root, int deep) {
        if (!root) return;
        ++deep;
        if (!root->left && !root->right) {
            if (deep > max_deep) {
                max_deep = deep;
                sum = root->val;
            } else if (deep == max_deep) {
                sum += root->val;
            }
            return;
        }
        helper(root->left, deep);
        helper(root->right, deep);
    }
};

class Solution2 {

public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum;
        while (!q.empty()) {
            sum = 0;
            for (int s = q.size()-1; s >= 0; --s) {
                root = q.front(); q.pop();
                sum += root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return sum;
    }
};
