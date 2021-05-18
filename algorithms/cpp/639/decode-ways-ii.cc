#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 和 91 题类似
     */
    int numDecodings(string s) {
        vector<long> dp(s.length());
        dp[0] = count(s[0]);
        for (int i = 1; i < s.length(); ++i) {
            dp[i] = (count(s[i]) * dp[i-1]) % MODULO;
            dp[i] += (count(s[i-1], s[i]) * (i>=2? dp[i-2]: 1)) % MODULO;
            dp[i] %= MODULO;
        }
        return dp.back();
    }

private:
    static int const MODULO = 1e9 + 7;
    inline int count(char c) {
        if (c == '*') return 9;
        return c!='0';
    }

    inline int count(char a, char b) {
        switch (a) {
        case '0': return 0;
        case '1': return ('*' == b)? 9: 1;
        case '2': return ('*' == b)? 6: (b<='6');
        case '*': return ('*' == b)? 15: 1+(b<='6');
        default: return 0;
        }
    }
};
