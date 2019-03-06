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

void random_pivot(vector<int> &arr, int start, int end, int *pivot)
{
    int mid = start+(end-start)/2;
    int idx = start;
    if (arr[start] < arr[mid])
        idx = mid;
    if (arr[idx] > arr[end])
        idx = end;

    *pivot = arr[idx];
    swap(arr[start], arr[idx]);
    _D("pivot: %d\n", *pivot);
}

static int _solve(vector<int> &arr, int start, int end, int k)
{
    if (start == end && start == k)
        return arr[k];

    int mid;
    int pivot;
    random_pivot(arr, start, end, &pivot);
    /* from the bigger to the smaller */
    int l = start+1, r = end;
    while (l < r) {
        while (l < r && arr[l] >= pivot)
            ++l;
        while (l < r && pivot > arr[r])
            --r;
        if (l < r) swap(arr[l], arr[r]);
    }
    if (arr[l] >= pivot) {
        swap(arr[start], arr[l]);
        mid = l;
    } else {
        swap(arr[start], arr[l-1]);
        mid = l-1;
    }

    if (k == mid) {
        return arr[mid];
    } else if (k < mid) {
        return _solve(arr, start, mid-1, k);
    } else {
        return _solve(arr, mid+1, end, k);
    }
}

int solve(vector<int> &arr, int k)
{
    return _solve(arr, 0, arr.size()-1, k-1);
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
