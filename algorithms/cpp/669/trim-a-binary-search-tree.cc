#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
    left(left), right(right) {}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        if (root->val < low) {
            TreeNode* right = root->right;
            root->right = nullptr;
            destroy_tree(root);
            return trimBST(right, low, high);
        }

        if (root->val > high) {
            TreeNode* left = root->left;
            root->left = nullptr;
            destroy_tree(root);
            return trimBST(left, low, high);
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }

private:
    void destroy_tree(TreeNode* root) {
    }
};
