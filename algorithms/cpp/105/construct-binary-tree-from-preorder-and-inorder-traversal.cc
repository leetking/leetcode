#include <vector>
#include <map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) { }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preidx = 0;
        inidxes.clear();
        /* 一个小优化 */
        for (int i = 0; i < inorder.size(); ++i)
            inidxes[inorder[i]] = i;
        return helper(preorder, inorder, 0, inorder.size());
    }

private:
    int preidx;
    map<int, int> inidxes;

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int inlo, int inhi) {
        if (preidx >= preorder.size() || inlo < inhi) return nullptr;
        int inidx = inidxes[preorder[preidx]];
        TreeNode* root = new TreeNode(preorder[preidx]);
        ++preidx;
        root->left = helper(preorder, inorder, inlo, inidx-1);
        root->right = helper(preorder, inorder, inidx+1, inhi);
        return root;
    }
};
