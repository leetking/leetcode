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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> traces;
        vector<int> rst;
        heigh_of_k(target, k, rst);
        distance(root, target, k, traces, rst);
        return rst;
    }

private:
    bool distance(TreeNode* root, TreeNode* target, int k, vector<TreeNode*>& traces, vector<int>& rst) {
        if (!root) return false;
        traces.push_back(root);
        if (root == target) {
            for (int i = traces.size() - 2; i >= 0; --i) {
                int d = traces.size() - 1 - i;
                if (d == k) {
                    rst.push_back(traces[i]->val);
                    return true;
                }
                if (traces[i]->left == traces[i+1])
                    heigh_of_k(traces[i]->right, k-d-1, rst);
                else
                    heigh_of_k(traces[i]->left, k-d-1, rst);
            }
            return true;
        }
        bool found = distance(root->left, target, k, traces, rst)
            || distance(root->right, target, k, traces, rst);
        traces.pop_back();
        return found;
    }

    void heigh_of_k(TreeNode* root, int h, vector<int>& rst) {
        if (!root || h < 0) return;
        if (0 == h) {
            rst.push_back(root->val);
            return;
        }
        heigh_of_k(root->left, h-1, rst);
        heigh_of_k(root->right, h-1, rst);
    }
};

/**
 * 方法二：构建为一个图，然后遍历
 */

int main()
{
    return 0;
}
