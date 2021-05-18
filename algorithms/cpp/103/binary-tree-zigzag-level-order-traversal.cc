#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <deque>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool l2r = true;    // from left to right
        vector<vector<int>> ret;
        while (!dq.empty()) {
            auto size = dq.size();
            vector<int> level;
            for (unsigned i = 0; i < size; i++) {
                TreeNode* node;
                if (l2r) {
                    node = dq.front();
                    dq.pop_front();
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                } else {
                    node = dq.back();
                    dq.pop_back();
                    /* 注意 right 和 left 的顺序，插入的是头部 */
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
                level.push_back(node->val);
            }
            l2r = !l2r;
            ret.push_back(level);
        }

        return ret;
    }
};

/* 方法二：普通层次遍历，然后对遍历结果逆序 */

int main()
{
    return 0;
}
