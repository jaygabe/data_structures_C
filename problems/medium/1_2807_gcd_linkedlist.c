#include <stdio.h>

// Definition for singly-linked list.
struct ListNode 
{
    int val;
    struct ListNode *next;
};

// Time Complexity: O(log(min(a, b)))
// Find the GCD of two integers
int gcd(int a, int b) 
{
    // declare remainder
    int r;
    // While the remainder of a and b
    // is greater than 0
    while((a % b) > 0) 
    {
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

struct ListNode *createNode(int val) 
{

    // Allocate space the size of the ListNode
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    newNode->val = val;
    // Space still prereserved
    newNode->next = NULL;
    // Return pointer to 
    return newNode;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head)
{
    // If there is no initial node or the first node does not have a next node
    // Just return the head because there are not two nodes to place a GCD between
    if(head == NULL || head->next == NULL) return head;

    // Create a reference to the head node we were given
    struct ListNode *curr = head;
    // Create a reference to what will become the next node
    struct ListNode *next = NULL;

    // While there is a node at our current node
    // and there is a node at the next node position
    while(curr != NULL && curr->next != NULL) 
    {
        // Store the node that comes after current node
        // in our next variable
        next = curr->next;

        // Find out what the GCD of our current and next node is
        int div = gcd(curr->val, curr->next->val);
        // Use that GCD to create a brand new node
        // We will place this between current and next nodes
        struct ListNode *temp = createNode(div);
        // Point the temp->next pointer to our next node
        temp->next = curr->next;
        // Point our curr->next pointer to our temp node
        curr->next = temp;
        // Move current to our next node
        curr = next;
    } 

    return head;
}