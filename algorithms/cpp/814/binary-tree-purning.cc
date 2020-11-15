#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        return prune_tree(&root);
    }

private:
    TreeNode* prune_tree(TreeNode** root) {
        if (!*root) return nullptr;
        prune_tree(&(*root)->left);
        prune_tree(&(*root)->right);
        if ((*root)->val == 0 && !(*root)->left && !(*root)->right) {
            delete *root;
            *root = nullptr;
            return nullptr;
        }
    }
};
