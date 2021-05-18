#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right) { }
    TreeNode(int val): TreeNode(val, nullptr, nullptr) { }
    TreeNode(): TreeNode(0) { }
};

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> rst;
        sort(arr.begin(), arr.end());
        int lo = 0;
        int hi = arr.size()-1;
        int m = arr[(arr.size()-1)/2];
        while (k--) {
            int d1 = abs(arr[lo]-m);
            int d2 = abs(arr[hi]-m);
            if (d1 > d2 || (d1 == d2 && arr[lo] > arr[hi]))
                rst.push_back(arr[lo++]);
            else
                rst.push_back(arr[hi--]);
        }
        return rst;
    }
};

int main()
{
    return 0;
}
