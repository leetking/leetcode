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

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        for (; root; root = root->left)
            stk.push(root);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = stk.top();
        int ret = node->val;
        stk.pop();
        node = node->right;
        for (; node; node = node->left)
            stk.push(node);
        return ret;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

private:
    stack<TreeNode*> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    return 0;
}
