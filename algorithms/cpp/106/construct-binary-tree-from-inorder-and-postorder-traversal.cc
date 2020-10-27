#include <map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) { }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postidx = postorder.size()-1;
        inidxes.clear();
        for (int i = 0; i < inorder.size(); ++i)
            inidxes[inorder[i]] = i;
        return helper(inorder, postorder, 0, inorder.size()-1);
    }

private:
    int postidx;
    map<int, int> inidxes;

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inlo, int inhi) {
        if (postidx < 0 || inlo > inhi) return nullptr;
        int val = postorder[postidx];
        --postidx;
        int inidx = inidxes[val];
        TreeNode* root = new TreeNode(val);
        root->right = helper(inorder, postorder, inidx+1, inhi);
        root->left = helper(inorder, postorder, inlo, inidx-1);
        return root;
    }
};
