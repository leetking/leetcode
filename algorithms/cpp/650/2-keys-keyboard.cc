#include <climits>

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * 更好的递推：
     * 如果 d | n 那么 f(n) = f(n/d) + d, 复制 n/d，d-1 次粘贴
     *
     * 不好的递推：
     * dp(i, p) 表示当前长度为 i 同时由粘贴长度为 p 得到的 i 的最小次数
     * 那么 dp(i, p)+1 -> dp(i+p, p)，继续粘贴
     *      dp(i, p)+2 -> dp(2*i, i)，复制粘贴
     *
     */
    int minSteps(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0; dp[1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int d = 2; d <= i; ++d) {
                if (i%d == 0)
                    dp[i] = min(dp[i], dp[i/d] + d);
            }
        }
        return dp.back();
    }
};

