#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * dp(i) 表示i结尾的值, 等于 dp(i-1) + dp(i-2)
     * 如果 s[i] 是有效字符 (不是'0') 加上 dp(i-1)
     * 如果 s[i-1, i] 是有效编号 加上 dp(i-2)
     */
    int numDecodings(string s) {
        vector<int> dp(s.length());
        dp[0] = (s[0] != '0');
        for (int i = 1; i < s.length(); ++i) {
            dp[i] = (s[i]!='0') * dp[i-1];
            if ('1' == s[i-1] || ('2' == s[i-1] && s[i] <= '6'))
                dp[i] += (i>=2)? dp[i-2]: 1;
        }
        return dp.back();
    }
};
