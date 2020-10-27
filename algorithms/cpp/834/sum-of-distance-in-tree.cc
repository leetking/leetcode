#include <vector>
#include <set>


using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree = vector<vector<int>>(N);
        parents = vector<int>(N, -1);
        counts = vector<int>(N);
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        auto ret = vector<int>(N);
        visited.clear();
        ret[0] = post_order(0);
        visited.clear();
        pre_order(0, N, ret);
        return ret;
    }

private:
    vector<vector<int>> tree;
    vector<int> parents;
    vector<int> counts;
    set<int> visited;

    int post_order(int root) {
        visited.insert(root);
        int sum = 0;
        counts[root] = 1;
        for (auto son : tree[root]) {
            if (!visited.count(son)) {
                parents[son] = root;         /* 生成树 */
                sum += post_order(son);
                sum += counts[son];
                counts[root] += counts[son];
            }
        }
        return sum;
    }

    void pre_order(int root, int N, vector<int>& ret) {
        visited.insert(root);
        for (auto son : tree[root]) {
            if (!visited.count(son)) {
                ret[son] = ret[parents[son]] - counts[son] + N - counts[son];
                pre_order(son, N, ret);
            }
        }
    }
};
