#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right) { }
    TreeNode(int val): TreeNode(val, nullptr, nullptr) { }
    TreeNode(): TreeNode(0) { }
};

/**
 * 方法：单调栈，单调递减的栈
 * https://leetcode.com/problems/maximum-binary-tree/discuss/106146/C%2B%2B-O(N)-solution
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        for (auto& num : nums) {
            auto node = new TreeNode(num);
            while (!stk.empty() && stk.back()->val < num) {
                node->left = stk.back();
                stk.pop_back();
            }
            if (!stk.empty())
                stk.back()->right = node;
            stk.push_back(node);
        }
        return stk.front();
    }
};

int main()
{
    return 0;
}
