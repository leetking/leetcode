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
    vector<int> pathInZigZagTree(int label) {
        vector<int> ret;
        while (label) {
            ret.push_back(label);
            label /= 2;
        }
        reverse(ret.begin(), ret.end());
        for (int h = ret.size()-1; h >= 1; h -= 2)
            ret[h-1] = (1<<h) + (1<<(h-1)) - 1 - ret[h-1];
        return ret;
    }
};


int main()
{
    Solution slu;
    slu.pathInZigZagTree(14);
    return 0;
}
