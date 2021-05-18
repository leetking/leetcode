#include <vector>

using namespace std;

class Solution {
public:
    /**
     * f(n) 表示数字 n 有 f(n) 个 1
     * f(2n) = f(n), f(2n+1) = f(n)+1
     */
    vector<int> countBits(int num) {
        vector<int> rst(num+1);
        for (int i = 0; 2*i <= num; i++) {
            rst[2*i] = rst[i];
            if (2*i+1 <= num)
                rst[2*i+1] = rst[i]+1;
        }
        return rst;
    }
    //for (int i = 1; i <= num; i++)
    //    rst[i] = rst[i>>1] + i%2;
};
