#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <stdarg.h>

#define ARR_SIZE(x)     ((int)(sizeof(x)/sizeof(x[0])))

#define MAX(x, y)   ((x)>(y)? (x): (y))
#define MIN(x, y)   ((x)<(y)? (x): (y))

#ifdef DEBUG
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

struct ListNode {
    int val;
    struct ListNode *next;
};


static void free_list(struct ListNode *list)
{
    struct ListNode *next;
    for (struct ListNode *p = list; p; p = next) {
        next = p->next;
        free(p);
    }
}


struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *ret = NULL;
    struct ListNode **ptail = &ret;
    int carry = 0;
    while (l1 || l2 || carry > 0) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum/10;

        struct ListNode *node = malloc(sizeof(*node));
        if (!node) goto quit;
        node->val = sum%10;
        node->next = NULL;
        *ptail = node;
        ptail = &node->next;
    }
    return ret;

quit:
    free_list(ret);
    return NULL;
}


/* ===== THE TEST AREA ===== */
static struct ListNode *get_list(int n)
{
    struct ListNode *list = NULL;
    struct ListNode **ptail = &list;
    for (int i = 0; i < n; i++) {
        struct ListNode *tmp = malloc(sizeof(*tmp));
        if (1 != scanf("%d", &tmp->val))
            goto quit;
        tmp->next = NULL;
        *ptail = tmp;
        ptail = &tmp->next;
    }
    return list;

quit:
    free_list(list);
    return NULL;
}


static void print_list(struct ListNode *list)
{
    for (; list; list = list->next)
        printf("%d", list->val);
    printf("\n");
}


int main(int argc, char **argv)
{
    int nl1, nl2;
    scanf("%d", &nl1);
    struct ListNode *l1 = get_list(nl1);
    scanf("%d", &nl2);
    struct ListNode *l2 = get_list(nl2);
    struct ListNode *sum = addTwoNumbers(l1, l2);
    print_list(l1);
    print_list(l2);
    print_list(sum);
    free_list(l1);
    free_list(l2);
    free_list(sum);
    return 0;
}
