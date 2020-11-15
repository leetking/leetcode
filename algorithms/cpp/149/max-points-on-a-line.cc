#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>

#include <cstdio>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right) { }
    TreeNode(int val): TreeNode(val, nullptr, nullptr) { }
    TreeNode(): TreeNode(0) { }
};

template<typename T>
T gcd(T a, T b)
{
    T t;
    while (0 != b) {
        t = a;
        a = b;
        b = t%b;
    }
    return a;
}

struct Fraction {
    int a, b;

    Fraction(int _a, int _b) {
        if (!_a && !_b) {
            a = b = 1;
            return;
        }
        int g = gcd(abs(_a), abs(_b));
        a = _a/g;
        b = _b/g;
        if (b < 0) {
            a = -a;
            b = -b;
        }
    }
    inline bool is_negtive_inf() const {
        return (this->a == -1 && this->b == 0);
    }
    inline bool is_postive_inf() const {
        return (this->a == 1 && this->b == 0);
    }
    friend bool operator<(const Fraction& x, const Fraction& y) {
        if (x.is_negtive_inf())
            return !y.is_negtive_inf();
        if (x.is_postive_inf() || y.is_negtive_inf())
            return false;
        if (y.is_postive_inf())
            return !x.is_postive_inf();
        return (x.a*y.b < y.a*x.b);
    }
    friend bool operator==(const Fraction& x, const Fraction& y) {
        return !(x < y) && !(y < x);
    }
};

class Line {
private:
    Fraction k, b;

public:
    Line(vector<int>& p1, vector<int>& p2)
        : k(p1[1]-p2[1], p1[0]-p2[0])
          , b(p1[1]*k.a - k.b*p1[0], k.a)
    { }

    friend bool operator<(const Line& l1, const Line& l2) {
        return (l1.k < l2.k) || (l1.k == l2.k && l1.b < l2.b);
    }
};

class Solution {
    public:
        int maxPoints(vector<vector<int>>& points) {
            if (points.size() == 0) return 0;
            int max_count = 0;
            for (unsigned i = 0; i < points.size(); ++i) {
                map<Line, int> counter;
                for (unsigned j = i+1; j < points.size(); ++j) {
                    max_count = max(max_count, ++counter[Line(points[i], points[j])]);
                }
            }
            return max_count+1;
        }
};

int main()
{
    vector<vector<int>> points = {{2, 3}, {3, 3}, {-5, 3}};
    Solution slu;
    cout << slu.maxPoints(points) << endl;
    return 0;
}
