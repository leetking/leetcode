#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define ARR_SIZE(x)     ((int)sizeof(x)/sizeof(x[0]))

#ifndef ONLINE_JUDGE
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct node_greater {
    bool operator()(ListNode *x, ListNode *y) {
        return x->val > y->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode*> &lists) {
        ListNode *ret = nullptr;
        ListNode **pret = &ret;
        priority_queue<ListNode*, vector<ListNode*>, node_greater> queue;
        for (auto list : lists) {
            if (list)
                queue.push(list);
        }

        ListNode *curr, *next;
        while (!queue.empty()) {
            curr = queue.top(); queue.pop();
            next = curr->next;
            *pret = curr;
            pret = &curr->next;
            *pret = nullptr;
            if (next)
                queue.push(next);
        }

        return ret;
    }
};
