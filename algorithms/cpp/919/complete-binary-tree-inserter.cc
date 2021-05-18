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

class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        if (!root) return;
        nodes.push_back(root);
        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[i]->left) nodes.push_back(nodes[i]->left);
            if (nodes[i]->right) nodes.push_back(nodes[i]->right);
        }
    }

    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        if (nodes.empty()) {
            nodes.push_back(node);
            return v;
        }
        int p = (nodes.size() - 1)/2;
        (nodes[p]->left? nodes[p]->right: nodes[p]->left) = node;
        nodes.push_back(node);
        return nodes[p]->val;
    }

    TreeNode* get_root() {
        if (nodes.empty()) return nullptr;
        return nodes[0];
    }
private:
    vector<TreeNode*> nodes;
};

/**
 * 只存储最后可能添加子树的节点
 */
class Solution2 {
};

int main()
{
    return 0;
}
