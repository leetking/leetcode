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
    template<typename T>
    void swap(T &a, T &b) {
        auto x = a;
        a = b;
        b = x;
    }

    void _permute(vector<int> &nums, vector<int>::size_type l,
            vector<int>::size_type r, vector<vector<int>> &ret) {
        if (l == r) {
            ret.push_back(nums);
            return;
        }

        for (vector<int>::size_type i = l; i < r; ++i) {
            /* 1. swap(nums[l], nums[i]); 2. std::swap(nums[l], nums[i]) */
            swap<int>(nums[l], nums[i]);
            _permute(nums, l+1, r, ret);
            swap<int>(nums[l], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ret;
        _permute(nums, 0, nums.size(), ret);
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
        vector<vector<int>> ret = s.permute(nums);
        permutation_print(ret);
    }
    return 0;
}
