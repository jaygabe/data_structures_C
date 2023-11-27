#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int val) {
    struct ListNode *create = malloc(sizeof(struct ListNode));
    create->val = val;
    create->next = NULL;
    return create;
}