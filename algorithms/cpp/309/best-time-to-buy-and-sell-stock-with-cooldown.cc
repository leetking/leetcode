#include <vector>

using namespace std;

class Solution {
public:
    /**
     * ref: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        vector<int> s0(prices.size());
        vector<int> s1(prices.size());
        vector<int> s2(prices.size());
        s1[0] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            s0[i] = max(s0[i-1], s2[i-1]);
            s1[i] = max(s1[i-1], s0[i-1] - prices[i]);
            s2[i] = s1[i-1] + prices[i];
        }
        return max(s0.back(), s2.back());
    }
};
