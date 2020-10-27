#include <stdio.h>
#include <limits.h>

#define ARR_MAX ((int)(5e4))

#define MIN(x, y)   ((x)<(y)? (x): (y))


int shortestSubarray(int *arr, int n, int k)
{
    static int sum[ARR_MAX], s = 0;
    int l = 0, r = 0, ret = n+1;
    for (int i = 0; i <= n; i++) {
        s += arr[i];
        if (i == n || arr[i] < 0) {
            if (l == 0 && sum[r-1] >= k) {
                ret = MIN(ret, r);
            }
            while (r >= 1 && l < r && sum[r-1] - sum[l] >= k) {
                ret = MIN(ret, r-l);
                l++;
            }
            while (l < r && s <= sum[r-1])
                r--;
        }
        if (i < n) {
            sum[r++] = s;
        }
    }

    return (ret <= n)? ret: -1;
}

int main()
{
    static int arr[ARR_MAX];
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
    }
    printf("%d\n", shortestSubarray(arr, n, k));
    return 0;
}
