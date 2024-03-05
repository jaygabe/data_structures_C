#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) return NULL;

    // Swap left and right children
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively invert the left and right subtree
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// Function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to print the tree in level-order
void printLevelOrder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct TreeNode* queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* node = queue[front++];

        printf("%d ", node->val);

        if (node->left != NULL) {
            queue[rear++] = node->left;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
}

int main() {
    // Example 1
    struct TreeNode* root1 = newNode(4);
    root1->left = newNode(2);
    root1->right = newNode(7);
    root1->left->left = newNode(1);
    root1->left->right = newNode(3);
    root1->right->left = newNode(6);
    root1->right->right = newNode(9);

    printf("Original Tree 1: ");
    printLevelOrder(root1);
    printf("\n");

    root1 = invertTree(root1);

    printf("Inverted Tree 1: ");
    printLevelOrder(root1);
    printf("\n\n");

    // Example 2
    struct TreeNode* root2 = newNode(2);
    root2->left = newNode(1);
    root2->right = newNode(3);

    printf("Original Tree 2: ");
    printLevelOrder(root2);
    printf("\n");

    root2 = invertTree(root2);

    printf("Inverted Tree 2: ");
    printLevelOrder(root2);
    printf("\n\n");

    // Example 3 (Empty Tree)
    struct TreeNode* root3 = NULL;

    printf("Original Tree 3: ");
    printLevelOrder(root3);
    printf("\n");

    root3 = invertTree(root3);

    printf("Inverted Tree 3: ");
    printLevelOrder(root3);
    printf("\n");

    return 0;
}