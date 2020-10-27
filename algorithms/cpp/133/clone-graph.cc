#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>

using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node(int val, vector<Node*> neighbors): val(val), neighbors(neighbors) { }
    Node(int val): Node(val, vector<Node*>()) { }
    Node(): Node(0) { }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        visited.clear();
        return helper(node);
    }

private:
    map<Node*, Node*> visited;
    Node *helper(Node *node) {
        if (!node) return nullptr;
        if (visited.count(node))
            return visited[node];
        Node* ret = new Node(node->val);
        visited[node] = ret;

        vector<Node*> neighbors;
        for (auto i : node->neighbors)
            neighbors.push_back(helper(i));
        node->neighbors = neighbors;
        return ret;
    }
};
