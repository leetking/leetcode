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

class UnionSet {
public:
    UnionSet(int n=1024) {
        map = new int[n+1]();
    }

    ~UnionSet() {
        delete[] map;
    }

    void add(int set, int x) {
        map[x] = set;
    }
    bool same(int a, int b) {
        return look(a) == look(b);
    }
    void merge(int a, int b) {
        a = look(a);
        b = look(b);
        if (map[a] > map[b])
            map[b] = a;
        else
            map[a] = b;
    }
private:
    int look(int x) {
        while (map[x] > 0)
            x = map[x];
        return x;
    }
    int *map;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionSet set(edges.size());
        for (auto edge : edges) {
            if (set.same(edge[0], edge[1]))
                return edge;
            set.merge(edge[0], edge[1]);
        }
        return {};
    }
};

int main()
{
    vector<vector<int>> edges = {
        {2, 3},
        {3, 4},
        {1, 5},
        {1, 4},
        {1, 2},
    };
    Solution slv;
    auto e = slv.findRedundantConnection(edges);
    cout << e[0] << " " << e[1] << endl;
    return 0;
}
