#include <iostream>

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        helper(&root, true, v, d);
        return root;
    }
private:
    void helper(TreeNode** root, bool left, int v, int d) {
        if (!*root && d > 1) return;
        if (d == 1) {
            TreeNode* node = new TreeNode(v);
            /* 等价写法 (left? node->left: node->right) = root; */
            if (left)
                node->left = *root;
            else
                node->right = *root;
            *root = node;
            return;
        }
        helper(&(*root)->left, true, v, d-1);
        helper(&(*root)->right, false, v, d-1);
    }
};

class Solution1 {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d, bool left) {
        if (!root && d > 1) return nullptr;
        if (d == 1) {
            TreeNode* node = new TreeNode(v);
            (left? node->left: node->right) = root;
            root = node;
            return node;
        }
        root->left = addOneRow(root->left, v, d-1, true);
        root->right = addOneRow(root->right, v, d-1, false);
        return root;
    }
};


int main()
{
    return 0;
}
