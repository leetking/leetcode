#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (!root) return {};
        queue<Node*> q;
        q.push(root);
        Node* last = root;
        Node* new_last;
        while (!q.empty()) {
            vector<int> level;
            for (;;) {
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                for (auto c : node->children) {
                    q.push(c);
                    new_last = c;
                }
                if (node == last)
                    break;
            }
            last = new_last;
            ret.push_back(level);
        }
        return ret;
    }
};
