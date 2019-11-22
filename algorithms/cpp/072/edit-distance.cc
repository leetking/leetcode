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
    int minDistance(string word1, string word2) {
        int rows = word1.size()+1;
        int cols = word2.size()+1;
        vector<vector<int>> dp{static_cast<string::size_type>(rows), vector<int>(cols, 0)};
        for (int i = 0; i < rows; i++)
            dp[i][0] = i;
        for (int j = 0; j < cols; j++)
            dp[0][j] = j;
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1+min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);
                }
            }
        }

        return dp[rows-1][cols-1];
    }
};


int main(int argc, char **argv)
{
    Solution slu;
    string word1, word2;
    while (cin >> word1 >> word2) {
        cout << slu.minDistance(word1, word2) << endl;
    }
    return 0;
}
