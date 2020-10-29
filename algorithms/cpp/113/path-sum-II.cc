#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> trace;
        vector<vector<int>> ans;
        dfs(root, trace, ans, sum);
        return ans;
    }

private:
    void dfs(TreeNode* root, vector<int>& trace, vector<vector<int>>& ans, int sum) {
        if (!root) return;
        trace.push_back(root->val);
        sum -= root->val;
        /* a leaf */
        if (!root->left && !root->right) {
            if (sum == root->val)
                ans.push_back(trace);
            trace.pop_back();
            return;
        }
        dfs(root->left, trace, ans, sum);
        dfs(root->right, trace, ans, sum);
        trace.pop_back();
    }
};
