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
    int maxLevelSum(TreeNode* root) {
        if (!root) return -1;
        queue<TreeNode*> level;
        int ret = -1;
        int max_sum = numeric_limits<int>::min();
        level.push(root);

        for (int l = 1; !level.empty(); ++l) {
            int size = level.size();
            int sum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = level.front();
                level.pop();
                sum += node->val;
                if (node->left) level.push(node->left);
                if (node->right) level.push(node->right);
            }
            if (sum > max_sum) {
                max_sum = sum;
                ret = l;
            }
        }
        return ret;
    }
};

int main()
{
    return 0;
}
