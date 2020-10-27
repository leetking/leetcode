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
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *list = nullptr;
        ListNode **tail = &list;
        bool first_group = true;
        int len = 0;
        for (ListNode *p = head; p; len++, p = p->next)
            ;

        for (int c = 0; c < len/k; c++) {
            bool isfirst = true;
            ListNode **last;
            ListNode *next, *p = nullptr;
            for (int i = 0; i < k; i++) {
                next = head->next;
                head->next = p;
                p = head;
                head = next;
                if (isfirst) {
                    last = &p->next;
                    isfirst = false;
                }
            }
            *tail = p;
            tail = last;
            if (first_group) {
                list = p;
                first_group = false;
            }
        }

        *tail = head;

        return list;
    }
};
