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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> rst;
        pre(root, rst);
        return rst;
    }
private:
    void pre(TreeNode* root, vector<int>& rst) {
        if (!root) return;
        rst.push_back(root->val);
        pre(root->left, rst);
        pre(root->right, rst);
    }
};

class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
    }
};

int main()
{
    return 0;
}
