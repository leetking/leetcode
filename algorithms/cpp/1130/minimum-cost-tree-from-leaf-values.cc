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
    int mctFromLeafValues(vector<int>& arr) {
        int maxs[LENGTH_MAX][LENGTH_MAX];
        int dp[LENGTH_MAX][LENGTH_MAX];
        for (unsigned i = 0; i < arr.size(); i++) {
            dp[i][i] = 0;
            maxs[i][i] = arr[i];
            for (unsigned j = i+1; j < arr.size(); j++)
                maxs[i][j] = max(maxs[i][j-1], arr[j]);
        }
        for (unsigned d = 1; d < arr.size(); ++d) {
            for (unsigned i = 0; i+d < arr.size(); ++i) {
                int min = numeric_limits<int>::max();
                for (unsigned k = 0; k+1 <= d; k++) {
                    int sum = maxs[i][i+k]*maxs[i+k+1][i+d] + dp[i][i+k] + dp[i+k+1][i+d];
                    if (sum < min)
                        min = sum;
                }
                dp[i][i+d] = min;
            }
        }

        return dp[0][arr.size()-1];
    }
private:
    static int const LENGTH_MAX = 40;
};


int main()
{
    Solution slv;
    vector<int> arr = {6, 2, 4};
    slv.mctFromLeafValues(arr);
    return 0;
}
