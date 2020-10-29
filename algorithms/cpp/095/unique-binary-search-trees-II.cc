#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) { }
    TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right) { }
};


class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (0 == n) return {};
        return helper(1, n);
    }
private:
    vector<TreeNode*> helper(int lo, int hi) {
        if (lo > hi) return {nullptr, };
        if (lo == hi) return {new TreeNode(lo), };  /* 可以优化常数 */

        vector<TreeNode*> trees;
        for (int root = lo; root <= hi; ++root) {
            auto left = helper(lo, root-1);
            auto right = helper(root+1, hi);
            for (auto& l : left) {
                for (auto& r : right) {
                    trees.push_back(new TreeNode(root, l, r));
                }
            }
        }
        return trees;
    }
};

int main()
{
    Solution slu;
    slu.generateTrees(3);
    return 0;
}
