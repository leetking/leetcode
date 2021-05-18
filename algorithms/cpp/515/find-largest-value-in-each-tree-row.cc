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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> rst;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            unsigned size = q.size();
            int max = numeric_limits<int>::min();
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->val > max)
                    max = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            rst.push_back(max);
        }

        return rst;
    }
};


int main()
{
    return 0;
}
