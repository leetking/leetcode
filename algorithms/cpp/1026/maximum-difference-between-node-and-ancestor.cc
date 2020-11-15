#include <algorithm>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* O(n*log(n))
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        int ret = 0;
        ret = max(maxAncestorDiff(root->left), ret);
        ret = max(maxAncestorDiff(root->right), ret);
        return max(preorder(root, root->val), ret);
    }

private:
    int preorder(TreeNode* root, int val) {
        if (!root) return 0;
        int ret = abs(root->val - val);
        ret = max(preorder(root->left, val), ret);
        return max(preorder(root->right, val), ret);
    }
};

/* O(n) */
class Solution2 {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return max(dfs(root->left, root->val, root->val),
                dfs(root->right, root->val, root->val));
    }

private:
    int dfs(TreeNode* root, int min_val, int max_val) {
        if (!root) return max_val - min_val;
        if (root->val > max_val)
            max_val = root->val;
        if (root->val < min_val)
            min_val = root->val;
        return max(dfs(root->left, min_val, max_val),
                dfs(root->right, min_val, max_val));
    }
};
