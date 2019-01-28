#include <cstdio>
#include <climits>
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

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

    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head) return nullptr;

        ListNode **p2;
        for (ListNode **p1 = &head; *p1 && (*p1)->next; p1 = p2) {
            p2 = &(*p1)->next;

            ListNode *next = (*p2)->next;
            (*p2)->next = *p1;
            *p1 = *p2;
            *p2 = next;
        }
        return head;
    }
};

static void list_free(ListNode *list)
{
    ListNode *next;
    for (ListNode *p = list; p; p = next) {
        next = p->next;
        delete p;
    }
}

static void list_print(ListNode *head)
{
    for (ListNode *p = head; p; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    Solution s = Solution();
    for (int n; cin >> n; ) {
        ListNode *list, **plist = &list;
        while (n--) {
            int x;
            cin >> x;
            (*plist) = new ListNode(x);
            plist = &(*plist)->next;
        }
        list_print(list);
        list = s.swapPairs(list);
        list_print(list);
        list_free(list);
    }

    return 0;
}
