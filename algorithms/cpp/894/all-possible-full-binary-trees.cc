#include <vector>
#include <map>
#include <algorithm>

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

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if (0 == N) return {};
        if (1 == N) return {new TreeNode(0)};
        vector<TreeNode*> ret;
        for (int i = 1; i <= N-2; i += 2) {
            auto lefts = allPossibleFBT(i);
            auto rights = allPossibleFBT(N-1 - i);
            for (auto left : lefts)
                for (auto right : rights)
                    ret.push_back(new TreeNode(0, left, right));
        }
        return ret;
    }
};

/**
 * dynamic plan: memorized result
 * 这里复用了节点，所以并不是严格意义上的多棵子树
 */
class Solution2 {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        map<int, vector<TreeNode*>> dp;
        return generate_trees(N, dp);
    }

private:
    vector<TreeNode*> generate_trees(int n, map<int, vector<TreeNode*>>& dp) {
        if (0 == n) return {};
        if (1 == n) {
            if (!dp.count(1))
                dp[1] = {new TreeNode(0)};
            return dp[1];
        }
        if (!dp.count(n)) {
            vector<TreeNode*> ret;
            for (int i = 1; i <= n-2; i += 2) {
                auto lefts = generate_trees(i, dp);
                auto rights = generate_trees(n-1 - i, dp);
                for (auto left : lefts)
                    for (auto right : rights)
                        ret.push_back(new TreeNode(0, left, right));
            }
            dp[n] = ret;
        }
        return dp[n];
    }
};
