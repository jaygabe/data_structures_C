#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int gcd(int a, int b) {
    int r;
    while((a % b) > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

struct ListNode *createNode(int val) {
    struct ListNode *create = malloc(sizeof(struct ListNode));
    create->val = val;
    create->next = NULL;
    return create;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;

    struct ListNode *curr = head;
    struct ListNode *next = NULL;
    while(curr != NULL && curr->next != NULL) {
        next = curr->next;

        int div = gcd(curr->val, curr->next->val);
        struct ListNode *temp = createNode(div);
        temp->next = curr->next;
        curr->next = temp;
        curr = next;
    } 

    return head;
}