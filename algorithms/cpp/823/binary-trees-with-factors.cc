#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 类似于两数乘机问题，同时注意动态规划
 * 注意：乘积溢出问题
 */
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long sum;
        vector<long> counts(arr.size(), 1);     // 修改为 long 防止 21 行乘积溢出
        sort(arr.begin(), arr.end());
        for (unsigned i = 0; i < arr.size(); i++) {
            int lo = 0, hi = i-1;
            while (lo <= hi) {
                if (product_cmp(arr[lo], arr[hi], arr[i]) == 0) {
                    int s = (counts[lo]*counts[hi])%MODULO;
                    if (arr[lo] != arr[hi])
                        s = (2*s)%MODULO;
                    counts[i] = (s+counts[i])%MODULO;
                    --hi;
                    ++lo;
                } else if (product_cmp(arr[lo], arr[hi], arr[i]) > 0) {
                    --hi;
                } else {
                    ++lo;
                }
            }
        }

        sum = 0;
        for (auto i : counts)
            sum = (sum+i)%MODULO;

        return sum;
    }
private:
    static int const MODULO = 1e9+7;
    int product_cmp(int a, int b, int c)
    {
        if (b > c/a)
            return 1;
        else if (b == c/a && c%a == 0)
            return 0;
        return -1;
    }
};

int main()
{
    Solution slv;
    cout << slv.numFactoredBinaryTrees(vector<int>()={2, 4, 5, 8, (int)1e9, (int)(1e9-1), (int)(1e9-2)}) << endl;
    return 0;
}
