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

struct pos_t {
    int r, c;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ret++;
                    spread(grid, i, j);
                }
            }
        }

        return ret;
    }

private:
    void spread(vector<vector<char>> &grid, int r, int c) {
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pos_t> queue;
        queue.push({r, c});
        grid[r][c] = '0';
        while (!queue.empty()) {
            auto pos = queue.front(); queue.pop();
            for (int i = 0; i < 4; i++) {
                int r = pos.r+dirs[i][0];
                int c = pos.c+dirs[i][1];
                if (0 <= r && r < rows && 0 <= c && c < cols
                        && '1' == grid[r][c]) {
                    grid[r][c] = '0';
                    queue.push({r, c});
                }
            }
        }
    }
};


int main(int argc, char **argv)
{
    vector<vector<char>> grid;
    string line;
    while (cin >> line) {
        vector<char> row;
        for (auto c : line)
            row.push_back(c);
        grid.push_back(row);
    }
    Solution slu;

    cout << slu.numIslands(grid) << endl;

    return 0;
}
