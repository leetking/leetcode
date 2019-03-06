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
private:
    template<typename T>
    T gcd(T a, T b) {
        while (b) {
            auto t = a;
            a = b;
            b = t%a;
        }
        return a;
    }

    template<typename T>
    void simplify(T &a, T &b) {
        auto g = gcd(a, b);
        a /= g;
        b /= g;
    }

    LL combine(int all, int selected) {
        /* (3, 2) = 3 ; (4, 2) = 6 */
        selected = min(selected, all-selected);
        LL a = 1, b = 1;
        for (; selected; --selected, --all) {
            a *= all;
            simplify(a, b);
            b *= selected;
            simplify(a, b);
        }
        return a;
    }

public:
    int uniquePaths(int m, int n) {
        return combine(m+n-2, n-1);
    }
};

int main(int argc, char **argv)
{
    Solution slu;
    for (int m, n; cin >> m >> n; )
        cout << slu.uniquePaths(m, n) << endl;
    return 0;
}
