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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> rst;
        post(root, rst);
        return rst;
    }
private:
    void post(TreeNode* root, vector<int>& rst) {
        if (!root) return;
        post(root->left, rst);
        post(root->right, rst);
        rst.push_back(root->val);
    }
};

int main()
{
    return 0;
}
