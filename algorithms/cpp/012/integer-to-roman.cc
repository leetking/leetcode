#include <cstdio>
#include <climits>
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;
typedef long long LL;

#define ARR_SIZE(x)     ((int)sizeof(x)/sizeof(x[0]))

#ifndef ONLINE_JUDGE
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

class Solution {
    private:
        int const ROMAN_MAX = 3999;

    public:
        string intToRoman(int num) {
            string ret;
            if (num > ROMAN_MAX)
                return ret;

            int units[] = {
                1, 5, 10, 50, 100, 500, 1000,
            };
            char const *coins[] = {
                "I", "V", "X", "L", "C", "D", "M",
            };

            for (int h = ARR_SIZE(units)-1; num; h--) {
                int d = num / units[h];

                if (0 == d)
                    continue;

                /* 9xxx */
                if (h&1 && (num >= units[h]/5*9)) {
                    ret.append(coins[h-1]);
                    ret.append(coins[h+1]);
                    num -= units[h]/5*9;
                } else {
                    if (d < 4) {
                        for (int i = 0; i < d; i++)
                            ret.append(coins[h]);
                    } else if (d == 4) {
                        ret.append(coins[h]);
                        ret.append(coins[h+1]);
                    }
                    num %= units[h];
                }
            }
            return ret;
        }
};

int main(int argc, char **argv)
{
    Solution s = Solution();
    int num;

    while (cin >> num) {
        cout << s.intToRoman(num) << endl;
    }

    return 0;
}
