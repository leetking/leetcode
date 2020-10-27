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

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        int len = 0;
        for (ListNode *p = head; p; len++, p = p->next)
            ;

        if (len == 0)
            return head;

        k = len - k%len;
        if (k == len)
            return head;

        ListNode **mid, **tail;
        int i = 1;
        for (ListNode *p = head; p; p = p->next) {
            if (i == k)
                mid = &p->next;

            if (i == len)
                tail = &p->next;

            i++;
        }

        *tail = head;
        head = *mid;
        *mid = nullptr;

        return head;
    }
};

int main(int argc, char **argv)
{
    return 0;
}
