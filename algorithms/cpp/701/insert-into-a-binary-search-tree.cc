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

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode** proot = &root;
        while (*proot) {
            if ((*proot)->val < val)
                proot = &(*proot)->right;
            else
                proot = &(*proot)->left;
        }
        *proot = new TreeNode(val);
        return root;
    }
};

int main()
{
    return 0;
}
