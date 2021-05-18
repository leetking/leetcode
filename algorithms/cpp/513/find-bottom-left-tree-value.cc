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
    int findBottomLeftValue(TreeNode* root, int dep=0) {
        if (!root) return -1;
        if (dep > max_dep) {
            max_dep = dep;
            leftmost = root->val;
        }
        findBottomLeftValue(root->left, dep+1);
        findBottomLeftValue(root->right, dep+1);
        return leftmost;
    }
private:
    int max_dep;
    int leftmost;
};

int main()
{
    return 0;
}
