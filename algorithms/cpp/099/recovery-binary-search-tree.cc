#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        prev = nullptr;
        first = second = nullptr;
        helper(root);
        if (first && second)
            swap(first->val, second->val);
    }

private:
    TreeNode *prev;
    TreeNode *first, *second;
    void helper(TreeNode *root) {
        if (!root) return;
        helper(root->left);
        if (prev && prev->val >= root->val) {
            if (!first) {
                first = prev;
                second = root;
            } else {
                second = root;
                return;
            }
        }
        prev = root;
        helper(root->right);
    }
};
