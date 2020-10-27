#include <cstdio>
#include <climits>
#include <cctype>
#include <cmath>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ARR_SIZE(x)     ((int)sizeof(x)/sizeof(x[0]))

#ifndef NDEBUG      /* fllow the macor `NDEBUG` from assert.h */
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

class Solution {
public:
    int shortestSubarray(vector<int>& arr, int k) {
        int ret = arr.size()+1;
        int s = 0;
        vector<int> sum;
        deque<int> queue;
        for (int i = 0; i < arr.size(); i++) {
            s += arr[i];
            sum.push_back(s);
            if (arr[i] < 0) {
                if (!queue.empty() && sum[queue.back()] >= k) {
                    ret = min(ret, queue.back()+1);
                }
                while (!queue.empty() && sum[queue.back()]-sum[queue.front()] >= k) {
                    ret = min(ret, queue.back()-queue.front());
                    queue.pop_front();
                }
                while (!queue.empty() && sum[queue.back()] >= s)
                    queue.pop_back();
            }
            queue.push_back(i);
        }

        if (!queue.empty() && sum[queue.back()] >= k) {
            ret = min(ret, queue.back()+1);
        }
        while (!queue.empty() && sum[queue.back()]-sum[queue.front()] >= k) {
            ret = min(ret, queue.back()-queue.front());
            queue.pop_front();
        }

        return (ret <= arr.size())? ret: -1;
    }
};

int main(int argc, char **argv)
{
    Solution slv = Solution();
    vector<int> arr;
    int n, k;
    cin >> n >> k;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }
    printf("%d\n", slv.shortestSubarray(arr, k));

    return 0;
}
