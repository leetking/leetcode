#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 当前最大值 = 不偷上一个 或者 偷这一个那么上一个就不能偷
     * f(i) = max{f(i-1), f(i-2) + nums[i]}
     */
    int rob3(vector<int>& nums) {
    }

    /**
     * f(i, 偷) = f(i-1, 不偷) + nums[i]
     * f(i, 不偷) = max{f(i-1, 不偷) + f(i-1, 偷)}
     */
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }

        return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
    }

    int rob2(vector<int>& nums) {
        int dp[2] = {0, nums[0]};  /* 状态方程只涉及前一个状态 */
        for (int i = 1; i < nums.size(); ++i) {
            int dp0 = dp[0];
            dp[0] = max(dp[0], dp[1]);
            dp[1] = dp0 + nums[i];
        }
        return max(dp[0], dp[1]);
    }
};
