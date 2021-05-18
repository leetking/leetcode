class Solution {
public:
    // f(n) = f(n-1) + f(n-2), f(0) = 0, f(1) = 1
    int fib(int n) {
        int f1 = 0, f2 = 1;
        while (n--) {
            int t = f1+f2;
            f1 = f2;
            f2 = t;
        }
        return f1;
    }
};
