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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode** n1 = &head;
        ListNode** n2;
        ListNode** p = &head;
        for (int i = 1; i < k; i++) {
            if (!*p)
                return head;
            p = &(*p)->next;
        }
        n2 = p;
        for (; *p && (*p)->next; p = &(*p)->next)
            n1 = &(*n1)->next;
        // 交换两个的值，偷个懒
        swap((*n2)->val, (*n1)->val);
        return head;
    }
};


int main()
{
    Solution slv;
    ListNode *list = new ListNode(1, new ListNode(2));
    slv.swapNodes(list, 1);
    return 0;
}
