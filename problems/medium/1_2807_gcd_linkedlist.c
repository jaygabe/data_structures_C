#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Time Complexity: O(log(min(a, b)))
// Find the GCD of two integers
int gcd(int a, int b) {
    // declare remainder
    int r;
    // While the remainder of a and b
    // is greater than 0
    while((a % b) > 0) {
        // Find the remainder
        r = a % b;
        // Store the value of b in a
        a = b;
        // Store the value of the remainder in b
        b = r;
    }
    // Return the final remainder
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