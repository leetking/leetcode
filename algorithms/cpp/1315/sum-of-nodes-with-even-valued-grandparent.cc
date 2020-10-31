#include <vector>
#include <set>
#include <map>
#include <algorithm>

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
    int sumEvenGrandparent(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }

private:
    int helper(TreeNode* root, TreeNode* parent, TreeNode* gparent) {
        if (!root) return 0;
        int ret = 0;
        if (gparent && !(gparent->val&0x1))
            ret += root->val;
        return ret + helper(root->left, root, parent) + helper(root->right, root, parent);
    }
};

int main()
{
    return 0;
}
