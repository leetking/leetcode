#include <vector>
#include <climits>
#include <queue>

using namespace std;

class Solution {
public:
    /**
     * dp(s) 表示跳到 s 需要的最少步数
     * dp(s+i) = min(dp(s+i), dp(s)+1), 1 <= i <= nums[s]
     *
     * 也可以当成一个图问题的最短路径来解
     */
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (unsigned s = 0; s < dp.size(); s++) {
            for (int i = 1; i <= nums[s] && s+i < dp.size(); i++)
                dp[s+i] = min(dp[s+i], dp[s]+1);
        }
        return dp[dp.size()-1];
    }

    /**
     * 采用Dijkstra来求最短路径
     * 最短路径 f(v) = min{f(u)+w(u, v)}, for all u->v
     */
    int jump2(vector<int>& nums) {
        using ipair = pair<int, int>;
        priority_queue<ipair, vector<ipair>, greater<ipair>> pq;    // 设置为降序排列
        vector<int> dist(nums.size(), INT_MAX);
        vector<bool> visited(nums.size(), false);
        pq.emplace(0, 0);
        dist[0] = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (visited[u])
                continue;
            visited[u] = true;
            for (int i = 1; i <= nums[u] && u+i < dist.size(); i++) {
                if (dist[u]+1 < dist[u+i]) {
                    dist[u+i] = dist[u]+1;
                    pq.emplace(dist[u+i], u+i);
                }
            }
        }
        return dist.back();
    }

    /**
     * TODO 理解贪心算法
     * 贪心算法 https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy
     */
    int jump3(vector<int>& nums) {
        int jumps = 0, curEnd = 0, curFarthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            curFarthest = max(curFarthest, i + nums[i]);
            if (i == curEnd) {
                jumps++;
                curEnd = curFarthest;
            }
        }
        return jumps;
    }
};

int main()
{
    Solution slv;
    slv.jump2(vector<int>()={2,3,1,1,4,4});

    return 0;
}
