#include <iostream>
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    }

private:
    vector<TreeNode*> delete_node_from_frost(vector<TreeNode*>& frost, int val) {
        vector<TreeNode*> ret;
        return ret;
    }
    vector<TreeNode*> delete_node(TreeNode* root, int val) {
        TreeNode** proot = &root;
        while (*proot) {
            if (val == (*proot)->val) {
                vector<TreeNode*> ret;
                if ((*proot)->left)
                    ret.push_back((*proot)->left);
                if ((*proot)->right)
                    ret.push_back((*proot)->right);
                if (root != *proot)
                    ret.push_back(root);
                delete *proot;
                *proot = nullptr;
                return ret;
            }
            proot = (val < (*proot)->val)? &(*proot)->left: &(*proot)->right;
        }
        return {};
    }
};

int main()
{
    return 0;
}
