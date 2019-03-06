#include <cstdio>
#include <climits>
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstring>
#include <cstdint>

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

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
    int search_left(vector<int> &nums, int target) {
        int l, r;
        for (l = 0, r = nums.size(); l < r; ) {
            int m = (l+r)/2;    /* l+(r-l)/2 */
            if (target <= nums[m])
                r = m;
            else
                l = m+1;
        }
        return (l < (int)nums.size() && target == nums[l])? l: -1;
    }

    int search_right(vector<int> &nums, int target) {
        int l, r;
        for (l = 0, r = nums.size(); l < r; ) {
            int m = (l+r)/2;
            if (target < nums[m])
                r = m;
            else
                l = m+1;
        }

        return (l >= 1 && target == nums[l-1])? l-1: -1;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) return {-1, -1};
        int rl = search_left(nums, target);
        if (-1 == rl) return {-1, -1};
        int rr = search_right(nums, target);

        return {rl, rr};
    }
};

int main(int argc, char **argv)
{
    Solution s = Solution();

    for (int n; cin >> n; ) {
        vector<int> nums;
        while (n--) {
            int x;
            cin >> x;
            nums.push_back(x);
        }
        int target;
        cin >> target;
        vector<int> ret = s.searchRange(nums, target);
        cout << ret[0] << ", " << ret[1] << endl;
    }
    return 0;
}
