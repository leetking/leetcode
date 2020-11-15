#include <random>

using namespace std;

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode** proot = &root;
        while (*proot) {
            if ((*proot)->val == key) {
                /* just a leaf */
                if (!(*proot)->left && !(*proot)->right) {
                    *proot = nullptr;
                    return root;
                }

                /* randomly delete from left or right subtre */
                TreeNode* (*steals[2])(TreeNode**) = {steal_max, steal_min};
                TreeNode** roots[2] = {&(*proot)->left, &(*proot)->right};
                mt19937 rand(time(nullptr));
                int b = (rand() >= rand.max()/2.0);
                if (!*roots[b])
                    b = !b;
                TreeNode* node = steals[b](roots[b]);
                node->left = (*proot)->left;
                node->right = (*proot)->right;
                /* need invoke delete? */
                *proot = node;
                return root;
            }
            proot = (key < (*proot)->val)? &(*proot)->left: &(*proot)->right;
        }
        return root;
    }

private:
    static TreeNode* steal_max(TreeNode** root) {
        while ((*root)->right)
            root = &(*root)->right;
        TreeNode* ret = *root;
        *root = ret->left;
        return ret;
    }

    static TreeNode* steal_min(TreeNode** root) {
        while ((*root)->left)
            root = &(*root)->left;
        TreeNode* ret = *root;
        *root = ret->right;
        return ret;
    }
};
