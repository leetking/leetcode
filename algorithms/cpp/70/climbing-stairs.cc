class Solution {
public:
    // f(n) = f(n-1)+f(n-2), f(0) = 1, f(1) = 1, f(2) = 2
    // 本质上就是斐波拉数列
    int climbStairs(int n) {
        int f0 = 0, f1 = 1;
        while (n--) {
            int t = f0 + f1;    // f(44)+f(45) 会溢出，所以挪位一下
            f0 = f1;
            f1 = t;
        }
        return f1;
    }
};
