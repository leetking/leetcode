class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        int left = kthSmallest(root->left, k);
        if (cnt >= k) return left;
        ++cnt;
        if (cnt == k)
            return root->val;
        return kthSmallest(root->right, k);
    }
private:
    int cnt = 0;
};

class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        int rst;
        helper(root, &k, &rst);
        return rst;
    }

private:
    void helper(TreeNode* root, int* n, int* rst) {
        if (!root) return;
        helper(root->left, n, rst);
        if (*n == 0) return;
        --*n;
        if (*n == 0) {
            *rst = root->val;
            return;
        }
        helper(root->right, n, rst);
    }
};
