#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.size() == 0) return ret;
        int ROW = matrix.size(), COL = matrix[0].size();
        int cnt = ROW + COL - 1;
        for (int i = 0; i < cnt; ++i) {
            int r = i, c = 0;
            if (i&0x1)
                swap(r, c);
            if (r >= ROW) {
                r = ROW-1;
                c = i - r;
            }
            if (c >= COL) {
                c = COL-1;
                r = i - c;
            }
            while (0 <= r && r < ROW && 0 <= c && c < COL) {
                ret.push_back(matrix[r][c]);
                if (i&0x1) {
                    ++r;
                    --c;
                } else {
                    --r;
                    ++c;
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
    };
    Solution slu;
    for (auto& e : slu.findDiagonalOrder(matrix))
        cout << e << " ";
    return 0;
}
