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
    void solveSudoku(vector<vector<char>> &board) {
        init(board);
        dp(board, 0);
    }

private:
    char row[9][9] = {""};
    char col[9][9] = {""};
    char block[3][3][9] = {{""}};
    vector<int> empty;
    void init(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = 1;
                    col[j][num] = 1;
                    block[i/3][j/3][num] = 1;
                } else {
                    empty.push_back(i*9+j);
                }
            }
        }
    }

    int dp(vector<vector<char>> &board, int idx) {
        if (idx >= empty.size()) return 1;
        int i = empty[idx]/9, j = empty[idx]%9;
        for (int num = 1; num < 10; num++) {
            if (!row[i][num] && !col[j][num] && !block[i/3][j/3][num]) {
                board[i][j] = num+'0';
                row[i][num] = 1;
                col[j][num] = 1;
                block[i/3][j/3][num] = 1;
                if (dp(board, idx+1) == 1)
                    return 1;
                row[i][num] = 0;
                col[j][num] = 0;
                block[i/3][j/3][num] = 0;
            }
        }

        return 0;
    }
};

int main(int argc, char **argv)
{
    return 0;
}
