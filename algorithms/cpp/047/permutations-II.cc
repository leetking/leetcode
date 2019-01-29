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
    /**
     * method 1. this
     * method 2. 031, generate from the most minimum sequence
     */
private:
    vector<int>::size_type unique_next(vector<int> &nums,
            map<int, bool> &exist, vector<int>::size_type pos) {
        vector<int>::size_type i;
        for (i = pos; i < nums.size() && exist[nums[i]]; ++i)
            ;
        return i;
    }

    void _permuteUnique(vector<int> &nums, vector<int>::size_type l,
            vector<vector<int>> &ret) {
        if (l == nums.size()) {
            ret.push_back(nums);
            return;
        }

        map<int, bool> exist;
        for (auto i = l; i < nums.size(); i = unique_next(nums, exist, i)) {
            exist[nums[i]] = true;
            swap(nums[l], nums[i]);
            _permuteUnique(nums, l+1, ret);
            swap(nums[l], nums[i]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> ret;
        _permuteUnique(nums, 0, ret);
        return ret;
    }
};

static void list_print(vector<int> &nums)
{
    for (auto i = nums.begin(); i != nums.end(); ++i)
        cout << *i << " ";
    cout << endl;
}

static void permutation_print(vector<vector<int>> &nums)
{
    for (auto i = nums.begin(); i != nums.end(); ++i)
        list_print(*i);
    cout << endl;
}

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
        vector<vector<int>> ret = s.permuteUnique(nums);
        permutation_print(ret);
    }
    return 0;
}
