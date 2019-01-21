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
#define ABS(x)      ((x)<0?  -(x): (x))

#ifdef DEBUG
# define _D(...)    printf(__VA_ARGS__)
#else
# define _D(...)    ((void)0)
#endif

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    if (!head || n <= 0) return NULL;

    struct ListNode **p = &head;

    for (struct ListNode *h = head; h; h = h->next, n--) {
        if (1 > n) {
            p = &(*p)->next;
        }
    }

    struct ListNode *befree = *p;
    *p = befree->next;
    free(befree);

    return head;
}

static void list_free(struct ListNode *list)
{
    struct ListNode *next;

    for (struct ListNode *p = list; p; p = next) {
        next = p->next;
        free(p);
    }
}

static struct ListNode *list_build_from_array(int *arr, int n)
{
    struct ListNode *list = NULL;
    struct ListNode **tail = &list;

    for (int i = 0; i < n; i++) {
        *tail = malloc(sizeof(**tail));
        (*tail)->val = arr[i];
        (*tail)->next = NULL;
        tail = &(*tail)->next;
    }

    return list;
}

static void list_print(struct ListNode *list)
{
    for (; list; list = list->next) {
        printf("%d ", list->val);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
#define ARR_SIZE_MAX    (1024)
    int n;
    int nums[ARR_SIZE_MAX];

    while (1 == scanf("%d", &n)) {
        int x;
        for (int i = 0; i < n; i++)
            scanf("%d", nums+i);
        scanf("%d", &x);
        struct ListNode *list = list_build_from_array(nums, n);
        list_print(list);
        list = removeNthFromEnd(list, x);
        list_print(list);
        list_free(list);
        printf("\n");
    }

    return 0;
}

