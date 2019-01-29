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
    /* O(n^2) */
    void nextPermutation(vector<int> &nums) {
        for (int i = nums.size()-1; i >= 0; --i) {
            if (nums[i] >= nums[nums.size()-1]) {
                auto x = nums[i];
                for (vector<int>::size_type j = i; j+1 < nums.size(); j++)
                    nums[j] = nums[j+1];
                nums[nums.size()-1] = x;
            } else {
                vector<int>::size_type j;
                for (j = i+1; j < nums.size() && nums[i] >= nums[j]; j++)
                    ;
                auto x = nums[i];
                nums[i] = nums[j];
                nums[j] = x;
                return;
            }
        }
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
