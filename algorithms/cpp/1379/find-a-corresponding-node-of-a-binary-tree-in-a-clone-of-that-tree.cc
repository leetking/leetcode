struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original || !cloned) return nullptr;
        if (target == original) return cloned;
        TreeNode *ret = getTargetCopy(original->left, cloned->left, target);
        if (ret) return ret;
        return getTargetCopy(original->right, cloned->right, target);
    }
};
