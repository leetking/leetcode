#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) return {};
        unordered_map<int, int> counts;
        int max_count = 0;
        post_travel(root, counts, max_count);
        vector<int> rst;
        for (auto i = counts.begin(); i != counts.end(); ++i) {
            if (i->second == max_count)
                rst.push_back(i->first);
        }
        return rst;
    }
private:
    int post_travel(TreeNode* root, unordered_map<int, int>& counts, int& max_count) {
        if (!root) return 0;
        int left  = post_travel(root->left, counts, max_count);
        int right = post_travel(root->right, counts, max_count);
        int sum = root->val + left + right;
        ++counts[sum];
        max_count = max(max_count, counts[sum]);
        return sum;
    }
};

int main()
{
    return 0;
}
