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
    int longestUnivaluePath(TreeNode* root) {
        int max_path = 0;
        dfs(root, max_path);
        return max_path;
    }

private:
    int dfs(TreeNode* root, int& path) {
        if (!root || (!root->left && !root->right))
            return 0;
        int left = dfs(root->left, path);
        int right = dfs(root->right, path);
        int ret = 0;
        if (root->left && root->left->val == root->val) {
            path = max(path, left+1);
            ret = max(ret, left+1);
        }
        if (root->right && root->right->val == root->val) {
            path = max(path, right+1);
            ret = max(ret, right+1);
        }
        if (root->left && root->left->val == root->val
                && root->right && root->right->val == root->val)
            path = max(path, left+right+2);
        return ret;
    }
};

int main()
{
    return 0;
}
