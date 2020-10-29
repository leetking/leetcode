#include <iostream>

class Solution {
public:
    int numTrees(int n) {
        int ans[] = {
            0,
            1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012,
            742900, 2674440, 9694845, 35357670, 129644790, 477638700,
            1767263190,
        };
        if (n <= 0 || n > 19) return 0;
        return ans[n];

        long long a = 1, b = 1;
        for (int i = 2*n, j = n; i >= n+2; i--, j--) {
            a *= i;
            simplify(a, b);
            b *= j;
            simplify(a, b);
        }
        return a;
    }

private:
    void simplify(long long& a, long long &b) {
        long long _a = a, _b = b;
        long long t;
        while (_b) {
            t = _a % _b;
            _a = _b;
            _b = t;
        }
        a /= _a;
        b /= _a;
    }
};

int main()
{
    Solution slu;
    for (int i = 1; i <= 19; ++i)
        std::cout << slu.numTrees(i) << ", ";
    return 0;
}
