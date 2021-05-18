#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) { }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) { }
};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int idx = 0;
        return helper(pre, &idx, post, 0, post.size()-1);
    }
private:
    /**
     * 树结构不唯一
     */
    TreeNode* helper(vector<int>& pre, int* idx, vector<int>& post, int lo, int hi) {
        if (*idx >= pre.size() || lo > hi) return nullptr;
        int val = pre[*idx];
        ++*idx;
        if (*idx >= pre.size())
            return new TreeNode(val);
        int mid;
        for (mid = hi; mid >= lo; --mid) {
            if (pre[*idx] == post[mid])
                break;
        }
        TreeNode* left = helper(pre, idx, post, lo, mid);
        TreeNode* right = helper(pre, idx, post, mid+1, hi-1);
        return new TreeNode(val, left, right);
    }
};

int main()
{
}
