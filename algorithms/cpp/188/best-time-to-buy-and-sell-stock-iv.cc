#include <climits>

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 第i天进行k次交易
     * dp[k, i] = max{dp[k, i-1], prices[i] - prices[j] + dp[k-1, j]}, 0 <= j <= i-1
     *          = max{dp[k, i-1], prices[i] + max{dp[k-1, j] - prices[j]}}, 0 <= j <= i-1
     *
     * TODO 对于 k > n/2 有优化, 考虑考虑
     */
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0));
        for (int kk = 1; kk <= k; ++kk) {
            int best = INT_MIN; /* dp[k-1, j] - prices[j] 的最大值 */
            for (int i = 1; i < prices.size(); ++i) {
                best = max(best, dp[kk-1][i-1]-prices[i-1]);
                dp[kk][i] = max(dp[kk][i-1], prices[i] + best);
            }
        }
        return dp.back().back();
    }
};
