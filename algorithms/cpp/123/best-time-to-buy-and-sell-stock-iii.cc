#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * 两段 dp: 左边部分 left(i) 表示 [0, i] 之间单次交易的最大值
     * right(i) 表示 [i, n-1] 之间单次交易的最大值
     *
     * O(n) 但是常数比较大
     *
     * 正确的 DP 方程
     * dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), 0 <= j <= i-1
     * k 是交易次数
     * i 是第几天交易
     */
    int maxProfit(vector<int>& prices) {
        vector<int> left(prices.size());
        vector<int> right(prices.size());
        /* [0, r] */
        int l = 0, r;
        int best = 0;
        for (r = 1; r < prices.size(); ++r) {
            if (prices[r] - prices[l] > best)
                best = prices[r] - prices[l];
            if (prices[r] < prices[l])
                l = r;
            left[r] = best;
        }

        /* [l, n-1] */
        r = prices.size()-1;
        best = 0;
        for (l = prices.size()-2; l >= 0; --l) {
            if (prices[r] - prices[l] > best)
                best = prices[r] - prices[l];
            if (prices[r] < prices[l])
                r = l;
            right[l] = best;
        }

        best = 0;
        for (int i = 0; i < prices.size(); ++i)
            best = max(best, left[i] + (i+1)<prices.size()? right[i+1]: 0);

        return best;
    }
};
