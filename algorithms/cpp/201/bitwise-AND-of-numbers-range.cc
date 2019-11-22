#include <cstdio>
#include <climits>
#include <cctype>
#include <cmath>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ARR_SIZE(x)     ((int)sizeof(x)/sizeof(x[0]))

#ifndef NDEBUG      /* fllow the macor `NDEBUG` from assert.h */
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (0 == m) return 0;

        int lm = lower(m);
        int ln = lower(n);
        if (ln > lm) return 0;
        int ret = 0;
        int flag = 0;
        while (lm) {
            if (!flag) {
                if ((m&lm) != (n&lm)) {
                    flag = 1;
                } else {
                    ret |= (m&lm);
                }
            }
            lm >>= 1;
        }
        return ret;
    }

private:
    int lower(int x) {
        unsigned int n = 1;
        while ((n<<1) <= (unsigned int)x)
            n <<= 1;
        return n;
    }
};

int main(int argc, char **argv)
{
    Solution slu;
    int m, n;
    while (cin >> m >> n) {
        cout << slu.rangeBitwiseAnd(m, n) << endl;
    }
    return 0;
}
