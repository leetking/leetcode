#include <algorithm>

using namespace std;

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
    int distributeCoins(TreeNode* root) {
        int ret = 0;
        postorder(root, ret);
        return ret;
    }

private:
    int postorder(TreeNode* root, int& ans) {
        if (!root) return 0;
        int left = postorder(root->left, ans);
        int right = postorder(root->right, ans);
        ans += abs(left) + abs(right);
        return left + right + root->val - 1;
    }
};
