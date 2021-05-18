#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right) { }
    TreeNode(int val): TreeNode(val, nullptr, nullptr) { }
    TreeNode(): TreeNode(0) { }
};


class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int dep = 0;
        return helper(root, &dep, 0);
    }

private:
    TreeNode* helper(TreeNode* root, int* dep, int level) {
        if (!root) return nullptr;
        if (!root->left && !root->right) {
            *dep = level;
            return root;
        }
        int dep1 = level, dep2 = level;
        TreeNode* left = helper(root->left, &dep1, 1+level);
        TreeNode* right = helper(root->right, &dep2, 1+level);

        if (dep1 == dep2) {
            *dep = dep1;
            return root;
        }

        if (dep1 < dep2) {
            *dep = dep2;
            return right;
        }

        *dep = dep1;
        return left;
    }
};


int main()
{
    return 0;
}
