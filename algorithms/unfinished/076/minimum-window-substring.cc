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
    string minWindow(string s, string t) {
        int minl = 0, minr = 0;
        int len = t.size();
        int alphabet[0xff+1];
        memset(alphabet, 0xff, sizeof(int)*(0xff+1));
        for (int i = 0; i < t.size(); ++i)
            ++alphabet[(int)t[i]];

        for (int i = 0; i < s.size(); ++i) {
            if (-1 == alphabet[(int)s[i]])
                continue;
            if (0 == alphabet[(int)s[i]])
                --len;
            ++alphabet[(int)s[i]];
            if (0 == len) {
                for (int j = minl; j <= i; ++j) {
                    if (-1 == alphabet[(int)s[j]])
                        continue;
                    --alphabet[(int)s[j]];
                    if (0 == alphabet[(int)s[j]]) {
                        ++len;
                        minl = j;
                        minr = i;
                        break;
                    }
                }
            }
        }

        return s.substr(minl, minr-minl+1);
    }
};

int main(int argc, char **argv)
{
    Solution slv;
    for (string s, t; cin >> s >> t; ) {
        cout << slv.minWindow(s, t) << endl;
    }
    return 0;
}
