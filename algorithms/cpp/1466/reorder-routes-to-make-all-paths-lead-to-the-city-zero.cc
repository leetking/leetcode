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

/**
 * 建无向图，然后遍历
 */
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for (auto& edge : connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(-edge[0]); // 妙妙的一步 -edge[0] 区分了添加的反向边
        }
        return visit(graph, vector<bool>(n)={}, 0);
    }
private:
    int visit(vector<vector<int>>& graph, vector<bool>& visited, int from) {
        if (visited[from]) return 0;
        int sum = 0;
        visited[from] = true;
        for (int to : graph[from]) {
            if (visited[abs(to)])
                continue;
            if (to > 0)
                sum ++;
            sum += visit(graph, visited, abs(to));
        }
        return sum;
    }
};

/**
 * 就是不断循环，从 0 开始蔓延，直到把所有边都遍历完
 */
class Solution1 {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> opens(n, false);
        opens[0] = true;
        int edges = 0;
        int rest = connections.size();
        for(int i = 0; rest; i = (i+1) % connections.size()) {
            vector<int> &road = connections[i];
            if(opens[road[0]] ^ opens[road[1]]) {
                edges += opens[road[0]];
                opens[road[0]] = true;
                opens[road[1]] = true;
                rest--;
            }
        }
        return edges;
    }
};


int main()
{
    return 0;
}
