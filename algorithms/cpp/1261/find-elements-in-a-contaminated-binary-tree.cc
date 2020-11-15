#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
    left(left), right(right) {}
};

class FindElements {
public:
    FindElements(TreeNode* root) {
        tree = root;
        if (!root) return;
        root->val = 0;
        initalize(tree);
    }

    bool find(int target) {
        if (target < 0) return false;
        vector<int> traces;
        for (;;) {
            traces.push_back(target);
            if (target == 0)
                break;
            target = (target-1)/2;
        }
        TreeNode* root = tree;
        for (int i = traces.size()-2; i >= 0; --i) {
            if (root->left && traces[i] == root->left->val)
                root = root->left;
            else if (root->right && traces[i] == root->right->val)
                root = root->right;
            else
                return false;
        }
        return true;
    }

private:
    TreeNode* tree;

    void initalize(TreeNode* root) {
        if (root->left) {
            root->left->val = root->val * 2 + 1;
            initalize(root->left);
        }
        if (root->right) {
            root->right->val = root->val * 2 + 2;
            initalize(root->right);
        }
    }
};

/**
 * other solution
 */
class FindElements2 {
public:
    FindElements2(TreeNode* root) {
        recover(root, 0);
        _root = root;
    }

    bool find(int target) {
        int upper = (target & 0x1) ? (target-1)>>1 : (target-2)>>1;
        return _find(upper, target) != NULL;
    }

private:
    void recover(TreeNode* root, int val) {
        root->val = val;
        if(root->left) recover(root->left, 2*val+1);
        if(root->right) recover(root->right, 2*val+2);
    }
    TreeNode* _find(int upper, int curr) {
        if(upper == 0) return (curr & 0x1) ? _root->left : _root->right;
        int target = curr;
        curr = upper;
        upper = (curr & 0x1) ? (curr-1)>>1 : (curr-2)>>1;
        TreeNode* node = _find(upper, curr);
        if(node) return (target & 0x1) ? node->left : node->right;
        else return NULL;
    }
    TreeNode* _root;
};
