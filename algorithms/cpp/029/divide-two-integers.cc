#include <cstdio>
#include <climits>
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstring>
#include <cstdint>

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
public:
    int divide(int divided, int dividsor) {
        int ans = 0;
        int sig = (divided>0 && dividsor<0) || (divided<0 && dividsor>0);
        /**
         * leetcode has a bug when it meets the below sentences.
         * I don't know why INT32_MIN != divided:(
         */
        divided = divided<0?   divided:  -divided;
        dividsor = dividsor<0? dividsor: -dividsor;
        if (INT32_MIN == divided && -1 == dividsor)
            return sig? INT32_MIN: INT32_MAX;

        /* TODO improve it */
        for (; divided <= dividsor; divided -= dividsor)
            ans++;

        return sig? -ans: ans;
    }
};

int main(int argc, char **argv)
{
    Solution s = Solution();
    int divided, dividsor;
    while (cin >> divided >> dividsor) {
        cout << s.divide(divided, dividsor) << endl;
    }
    return 0;
}
