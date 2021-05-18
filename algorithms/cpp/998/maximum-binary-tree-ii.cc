#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
    left(left), right(right) {}
};

class Solution1 {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        stack<TreeNode*> stk;
        while (root) {
            stk.push(root);
            root = root->right;
        }
        TreeNode* node = new TreeNode(val);
        while (!stk.empty() && stk.top()->val < val) {
            node->left = stk.top();
            stk.pop();
        }
        if (!stk.empty())
            stk.top()->right = node;
        // pop up utill buttom
        while (!stk.empty()) {
            node = stk.top();
            stk.pop();
        }
        return node;
    }
};


/* 单调栈 */
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        TreeNode** proot = &root;
        for (;;) {
            if (!*proot || (*proot)->val < val) {
                node->left = *proot;
                *proot = node;
                break;
            }
            proot = &(*proot)->right;
        }
        return root;
    }
};
