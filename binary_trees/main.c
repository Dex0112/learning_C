#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} node_t;

void insert(node_t *tree, int val);
void printBFS(node_t *current);
void printDFS(node_t *current);

int main() {
    node_t *tree = (node_t *)malloc(sizeof(node_t));
    /* set values explicitly, alternative would be calloc() */
    tree->val = 5;
    tree->left = NULL;
    tree->right = NULL;

    insert(tree, 8);
    insert(tree, 4);
    insert(tree, 3);

    printDFS(tree);
    printf("\n");
}

void insert(node_t *current, int val) {
    if (current == NULL)
        return;

    if (val < current->val) {
        if (current->left) {
            insert(current->left, val);
            return;
        }

        // Insert here
        node_t *node = (node_t *)malloc(sizeof(node_t));

        node->val = val;
        node->left = NULL;
        node->right = NULL;

        current->left = node;

        return;
    }

    // Insert to the right

    if (current->right) {
        insert(current->right, val);
        return;
    }

    node_t *node = (node_t *)malloc(sizeof(node_t));

    node->val = val;
    node->left = NULL;
    node->right = NULL;

    current->right = node;
}

void printDFS(node_t *current) {
    if (current->left)
        printDFS(current->left);

    if (current->right)
        printDFS(current->right);

    printf("%d ", current->val);
}
