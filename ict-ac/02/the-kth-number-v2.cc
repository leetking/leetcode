#include <cstdio>
#include <ctime>

#include <iostream>
#include <vector>

using namespace std;

#ifdef ONLINE_JUDGE
# define    _D(...)     ((void)0)
#else
# define    _D(...)     printf(__VA_ARGS__)
#endif

int solve(vector<int> &arr, int k)
{
    int n = arr.size();
    int lo = 0, hi = arr.size()-1;
    while (lo < hi) {
        int pivot = arr[lo + (hi-lo)/2];
        int i = lo-1, j = hi+1;
        for (;;) {
            while (arr[++i] < pivot)
                ;
            while (pivot < arr[--j])
                ;
            if (i >= j)
                break;
            swap(arr[i], arr[j]);
        }

        if (k == n-j)
            return arr[j];
        else if (k < n-j)
            lo = j+1;
        else
            hi = j-1;
    }

    return arr[lo];
}

int main()
{
    int n, k;
    while (cin >> n >> k) {
        vector<int> arr;
        while (n--) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        cout << solve(arr, k) << endl;
    }

    return 0;
}
