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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root, 0).first;
    }

private:
    pair<TreeNode*, int> helper(TreeNode* root, int dep) {
        if (!root) return {nullptr, -1};
        if (!root->left && !root->right) return {root, dep};
        auto left = helper(root->left, dep+1);
        auto right = helper(root->right, dep+1);
        if (left.second == right.second)
            return {root, left.second};
        if (left.second < right.second)
            return right;
        return left;
    }
};


int main()
{
    Solution slv;
    slv.lcaDeepestLeaves(nullptr);
    return 0;
}
