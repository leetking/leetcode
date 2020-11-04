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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> stk1, stk2;
        vector<int> vec;
        push_nodes(stk1, root1);
        push_nodes(stk2, root2);
        while (!stk1.empty() && !stk2.empty()) {
            if (stk1.top()->val < stk2.top()->val)
                vec.push_back(next(stk1));
            else
                vec.push_back(next(stk2));
        }
        while (!stk1.empty())
            vec.push_back(next(stk1));
        while (!stk2.empty())
            vec.push_back(next(stk2));
        return vec;
    }

private:
    void push_nodes(stack<TreeNode*>& stk, TreeNode* root) {
        for (; root; root = root->left)
            stk.push(root);

        // std::exchange(old_val, new_val) -> old_val C++14之后添加的函数
        //while (root)
        //    stk.push(exchange(root, root->left));
    }

    int next(stack<TreeNode*>& stk) {
        TreeNode* node = stk.top();
        stk.pop();
        push_nodes(stk, node->right);
        return node->val;
    }
};

int main()
{
    return 0;
}
