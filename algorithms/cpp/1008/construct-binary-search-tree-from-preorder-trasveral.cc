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

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);
    }

private:
    TreeNode* helper(vector<int>& preorder, int lo, int hi) {
        if (lo > hi) return nullptr;
        if (lo == hi) return new TreeNode(preorder[lo]);
        int root = preorder[lo];
        int mid;
        for (mid = lo+1; mid <= hi && preorder[mid] < root; ++mid)
            ;
        return new TreeNode(root, helper(preorder, lo+1, mid-1), helper(preorder, mid, hi));
    }
};


class Solution2 {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        vector<TreeNode*> stk;
        stk.push_back(root);
        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);
            TreeNode* parent = nullptr;
            while (!stk.empty() && stk.back()->val < preorder[i]) {
                parent = stk.back();
                stk.pop_back();
            }
            if (parent) {
                parent->right = node;
            } else if (!stk.empty()) {
                stk.back()->left = node;
            }
            stk.push_back(node);
        }
        return root;
    }
};


class Solution3 {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return helper(preorder, idx, numeric_limits<int>::max());
    }

private:
    TreeNode* helper(vector<int>& preorder, int &idx, int bound) {
        if (idx >= preorder.size() || preorder[idx] > bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = helper(preorder, idx, root->val);
        root->right = helper(preorder, idx, bound);
        return root;
    }
};


int main()
{
    return 0;
}
