#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to perform inorder traversal
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = malloc(100 * sizeof(int)); // Allocate memory for the result
    *returnSize = 0;
    struct TreeNode* stack[100]; // Stack for iterative traversal
    int top = -1;

    while (root || top != -1) {
        while (root) {
            stack[++top] = root; // Push the current node onto the stack
            root = root->left;  // Move to the left child
        }
        root = stack[top--];      // Pop the top node from the stack
        res[(*returnSize)++] = root->val; // Add the node's value to the result
        root = root->right;       // Move to the right child
    }
    return res;
}

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to build a binary tree from a level-order traversal
struct TreeNode* buildTree(const char** nodes, int size) {
    if (size == 0 || nodes[0] == NULL) return NULL;

    struct TreeNode** queue = malloc(size * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    struct TreeNode* root = createNode(atoi(nodes[0]));
    queue[rear++] = root;

    int i = 1;
    while (i < size) {
        struct TreeNode* current = queue[front++];
        if (i < size && nodes[i] != NULL) {
            current->left = createNode(atoi(nodes[i]));
            queue[rear++] = current->left;
        }
        i++;
        if (i < size && nodes[i] != NULL) {
            current->right = createNode(atoi(nodes[i]));
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);
    return root;
}

// Helper function to print an array
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i + 1 < size) printf(",");
    }
    printf("]\n");
}

// Main function to test the inorderTraversal function
int main() {
    // Example 1
    const char* nodes1[] = {"1", NULL, "2", "3"};
    struct TreeNode* root1 = buildTree(nodes1, 4);
    int returnSize1;
    printf("Input: root = [1,null,2,3]\n");
    int* result1 = inorderTraversal(root1, &returnSize1);
    printf("Output: ");
    printArray(result1, returnSize1);
    free(result1);

    // Example 2
    const char* nodes2[] = {"1", "2", "3", "4", "5", NULL, "8", NULL, NULL, "6", "7", "9"};
    struct TreeNode* root2 = buildTree(nodes2, 12);
    int returnSize2;
    printf("Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]\n");
    int* result2 = inorderTraversal(root2, &returnSize2);
    printf("Output: ");
    printArray(result2, returnSize2);
    free(result2);

    // Example 3
    const char* nodes3[] = {};
    struct TreeNode* root3 = buildTree(nodes3, 0);
    int returnSize3;
    printf("Input: root = []\n");
    int* result3 = inorderTraversal(root3, &returnSize3);
    printf("Output: ");
    printArray(result3, returnSize3);
    free(result3);

    // Example 4
    const char* nodes4[] = {"1"};
    struct TreeNode* root4 = buildTree(nodes4, 1);
    int returnSize4;
    printf("Input: root = [1]\n");
    int* result4 = inorderTraversal(root4, &returnSize4);
    printf("Output: ");
    printArray(result4, returnSize4);
    free(result4);

    return 0;
}
