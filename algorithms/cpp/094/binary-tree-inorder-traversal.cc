#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> nodes;
        helper(root, nodes);
        return nodes;
    }

private:
    void helper(TreeNode const *root, vector<int> &nodes) {
        if (!root) return;
        helper(root->left, nodes);
        nodes.push_back(root->val);
        helper(root->right, nodes);
    }
};
