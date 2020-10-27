#include <iostream>
#include <stack>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) { }
    TreeNode(int x): val(x), left(nullptr), right(nullptr) { }
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) { }
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        std::stack<TreeNode *> traces;
        bool has_prev = false;
        int prev;
        while (nullptr != root || !traces.empty()) {
            if (nullptr != root) {
                traces.push(root);
                root = root->left;
            } else {
                root = traces.top(); traces.pop();
                if (has_prev && prev > root->val)
                    return false;
                prev = root->val;
                has_prev = true;
                root = root->right;
            }
        }
        return true;
    }

    bool isValidBST2(TreeNode *root) {
        if (!root) return true;
        if (!isValidBST2(root->left))
            return false;
        if (has_prev && prev >= root->val)
            return false;
        prev = root->val;
        has_prev = true;
        return isValidBST2(root->right);
    }

private:
    int prev;
    bool has_prev = false;
};
