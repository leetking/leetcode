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
    int goodNodes(TreeNode* root) {
        int ret = 0;
        helper(root, numeric_limits<int>::min(), ret);
        return ret;
    }

private:
    void helper(TreeNode* root, int max_val, int& ret) {
        if (!root) return;
        if (root->val >= max_val) {
            ++ret;
            max_val = root->val;
        }
        helper(root->left, max_val, ret);
        helper(root->right, max_val, ret);
    }
};

int main()
{
    return 0;
}
