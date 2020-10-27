#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define ARR_SIZE(x)     ((int)sizeof(x)/sizeof(x[0]))

#ifndef ONLINE_JUDGE
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

/* ref https://leetcode.com/problems/maximal-rectangle/discuss/29054/Share-my-DP-solution */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (0 == matrix.size()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> length{matrix.size(), vector<int>(n, 0)};
        for (int i = 0; i < m; ++i) {
            int l = 0;
            for (int j = n-1; j >= 0; --j) {
                if ('1' == matrix[i][j])
                    ++l;
                else
                    l = 0;
                length[i][j] = l;
            }
        }

        int ret = 0;
        for (int j = 0; j < n; ++j) {
            stack<int> s;
            for (int i = 0; i <= m; ++i) {
                int h = (i == m)? 0: length[i][j];
                if (s.empty() || h >= length[s.top()][j]) {
                    s.push(i);
                } else {
                    int tp = s.top(); s.pop();
                    ret = max(ret, length[tp][j]*(s.empty()? i: i-s.top()-1));
                    --i;
                }
            }
        }

        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution slu;
    for (int m, n; cin >> m >> n; ) {
        vector<vector<char>> matrix(m, vector<char>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;
                scanf("%d", &x);
                matrix[i][j] = x+'0';
            }
        }
        cout << slu.maximalRectangle(matrix) << endl;
    }
    return 0;
}
