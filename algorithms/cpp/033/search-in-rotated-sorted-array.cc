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
    int bin_search(vector<int> &nums, int l, int r, int target) {
        while (l < r) {
            int m = (l+r)/2;
            if (target == nums[m]) return m;
            if (target < nums[m])
                r = m;
            else
                l = m+1;
        }

        return -1;
    }

public:
    int search(vector<int> &nums, int target) {
        for (int l = 0, r = nums.size(); l < r; ) {
            int m = (l+r)/2;
            if (target == nums[m]) return m;
            if (nums[l] < nums[m]) {
                if (target < nums[m]) {
                    int ret = bin_search(nums, l, m, target);
                    if (-1 != ret) return ret;
                }
                l = m+1;
            } else {
                if (target > nums[m]) {
                    int ret = bin_search(nums, m+1, r, target);
                    if (-1 != ret) return ret;
                }
                r = m;
            }
        }

        return -1;
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
        cout << s.search(nums, target) << endl;
    }
    return 0;
}
