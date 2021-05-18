#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 贪心的方法：front 表示目前能到达的最远地方
     */
    bool canJump(vector<int>& nums) {
        int front = 0;
        for (int i = 0; i <= front; ++i) {
            front = max(front, i+nums[i]);
            if (front >= nums.size()-1)
                return true;
        }
        return false;
    }
};
