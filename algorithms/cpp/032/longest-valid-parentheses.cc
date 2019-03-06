#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define ARR_SIZE(x)     ((int)sizeof(x)/sizeof(x[0]))

#ifndef ONLINE_JUDGE
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> last;
        vector<int> counts(s.length(), -1);
        for (unsigned i = 0; i < s.length(); ++i) {
            if ('(' == s[i]) {
                last.push(i);
            } else if (')' == s[i] && !last.empty()) {
                int lst = last.top(); last.pop();
                counts[i] = (lst >= 1 && -1 != counts[lst-1])?
                        counts[lst-1]: lst;
            }
        }

        auto ret = 0;
        for (unsigned i = 0; i < counts.size(); ++i)
            ret = max(ret, (counts[i] != -1)? ((int)i+1 - counts[i]): 0);
        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution slu;
    for (string s; getline(cin, s); )
        cout << slu.longestValidParentheses(s) << endl;

    return 0;
}
