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
public:
    /* O(n) */
    void nextPermutation(vector<int> &nums) {
        int i;
        for (i = nums.size()-2; i >= 0; --i) {
            if (nums[i] < nums[i+1])
                break;
        }
        /* reverse */
        vector<int>::size_type j;
        for (j = 0; j < (nums.size()-i-1)/2; ++j) {
            auto x = nums[i+1+j];
            nums[i+1+j] = nums[nums.size()-1-j];
            nums[nums.size()-1-j] = x;
        }
        if (i <= -1) return;

        for (j = i+1; j < nums.size() && nums[i] >= nums[j]; ++j)
            ;
        auto x = nums[i];
        nums[i] = nums[j];
        nums[j] = x;
        return;
    }
};

static void list_print(vector<int> const *nums)
{
    for (auto i = nums->begin(); i != nums->end(); ++i)
        cout << *i << " ";
    cout << endl;
}

int main(int argc, char **argv)
{
    Solution s = Solution();

    for (int num; cin >> num; ) {
        vector<int> nums;
        while (num--) {
            int x;
            cin >> x;
            nums.push_back(x);
        }
        list_print(&nums);
        s.nextPermutation(nums);
        list_print(&nums);
    }

    return 0;
}
