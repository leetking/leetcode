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
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return nullptr;
        bstToGst(root->right);
        sum += root->val;
        root->val = sum;
        bstToGst(root->left);
        return root;
    }
private:
    int sum = 0;
};

int main()
{
    return 0;
}
