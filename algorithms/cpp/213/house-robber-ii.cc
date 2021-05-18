#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    /**
     * 类似 house-robber 只是对第一个单独做了区分，最后一个不取的话最大值可能为 第一个不取或第一个取
     * 最后一个取的话，最大值为 第一个不取且前一个不取
     */
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int len = nums.size();
        vector<int> dp0(len, 0);
        vector<int> dp1(len, 0);
        dp0[0] = 0; dp0[1] = nums[1];
        dp1[0] = nums[0]; dp1[1] = dp1[0];
        int i;
        for (i = 2; i < len-1; i++) {
            dp0[i] = max(dp0[i-1], dp0[i-2]+nums[i]);
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i]);
        }
        return max(max(dp0[i-2]+nums[i], dp0[i-1]), dp1[i-1]);
    }

    int rob2(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        /* 不选最后一个 或者 不选择第一个 */
        return max(rob(nums, 0, len-2), rob(nums, 1, len-1));
    }

private:
    int rob(vector<int>& nums, int lo, int hi) {
        if (lo > hi) return 0;
        if (hi-lo == 0) return nums[lo];
        if (hi-lo == 1) return max(nums[lo], nums[lo+1]);
        /* hi - lo + 1 >= 3 */
        vector<int> dp(hi-lo+1, 0);
        dp[0] = nums[lo];
        dp[1] = max(nums[lo], nums[lo+1]);
        for (int i = 2; i < hi-lo+1; i++)
            dp[i] = max(dp[i-1], dp[i-2]+nums[lo+i]);
        return dp[hi-lo];
    }
};
