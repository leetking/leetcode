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
    typedef long long LL;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<LL>> paths(m, vector<LL>(n, 0));
        paths[0][0] = !obstacleGrid[0][0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == i && j >= 1)
                    paths[i][j] = !obstacleGrid[i][j] && paths[i][j-1];
                if (0 == j && i >= 1)
                    paths[i][j] = !obstacleGrid[i][j] && paths[i-1][j];

                if (i >= 1 && j >= 1 && !obstacleGrid[i][j])
                    paths[i][j] = paths[i-1][j]+paths[i][j-1];
            }
        }
        return paths[m-1][n-1];
    }
};

int main(int argc, char **argv)
{
    Solution slu;
    for (int m, n; cin >> m >> n; ) {
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                scanf("%d", &grid[i][j]);
        }
        cout << slu.uniquePathsWithObstacles(grid) << endl;
    }
    return 0;
}
