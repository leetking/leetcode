#include <cstdio>
#include <climits>
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

/* using std::vector */
using namespace std;
typedef long long LL;

#define ARR_SIZE(x)     ((int)sizeof(x)/sizeof(x[0]))

#ifndef ONLINE_JUDGE
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

/* TODO implement a iterative version */
class Solution {
private:
    void walk(int num, int left, int right, string *track,
            vector<string> *ret) {
        if (left > num || right > num)
            return;

        if (2*num == left + right) {
            ret->push_back(*track);
            return;
        }

        track->push_back('(');
        walk(num, left+1, right, track, ret);
        track->pop_back();
        if (left > right) {
            track->push_back(')');
            walk(num, left, right+1, track, ret);
            track->pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string track;
        walk(n, 0, 0, &track, &ret);

        return ret;
    }
};

int main(int argc, char **argv)
{
    int num;
    Solution s = Solution();
    while (cin >> num) {
        auto ret = s.generateParenthesis(num);
        for (auto s = ret.begin(); s != ret.end(); s++)
            cout << *s << endl;
        cout << endl;
    }
    return 0;
}
