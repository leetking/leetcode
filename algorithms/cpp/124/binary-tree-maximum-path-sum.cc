#include <limits>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

/* ref https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/39775/Accepted-short-solution-in-Java */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        max_val = numeric_limits<int>::min();
        helper(root);
        return max_val;
    }

private:
    int max_val;
    /**
     * 后序遍历每一个节点，计算出当前经过当前节点的最大路径和并更新 max_val
     * 并返回从当前路径往下所能得到的最大路径和
     */
    int helper(TreeNode *root) {
        if (!root) return 0;
        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));
        max_val = max(max_val, left + right + root->val);
        return max(left, right) + root->val;
    }
};
