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
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int max_area = 0;
        for (int i = 0; i <= heights.size(); ++i) {
            int h = (i == heights.size())? 0: heights[i];
            if (s.empty() || h >= heights[s.top()]) {
                s.push(i);
            } else {
                /* 以 heights[s.top()] 为矩形的高的面积 */
                int tp = s.top(); s.pop();
                max_area = max(max_area, heights[tp]*(s.empty()? i: i-s.top()-1));
                --i;
            }
        }
        return max_area;
    }
};

int main(int argc, char **argv)
{
    Solution slv;
    for (int n; cin >> n; ) {
        int x;
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            cin >> x;
            arr.push_back(x);
        }
        cout << slv.largestRectangleArea(arr) << endl;
    }
    return 0;
}
