#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    /**
     * dp[i]: 以 nums[i] 结尾的最大和
     * dp[i] = dp[i-1] + nums[i] if dp[i-1] >= 0;
     *       = nums[i] if dp[i-1] < 0;
     */
    int maxSubArray(vector<int>& nums) {
        int max = numeric_limits<int>::min();
        int sum = 0;
        for (auto num : nums) {
            sum = num + ((sum < 0)? 0: sum);
            if (sum > max)
                max = sum;
        }
        return max;
    }
};

int main()
{
    return 0;
}
