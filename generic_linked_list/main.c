#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void *val;
    struct node *next;
} node_t;

node_t *create_node(void *val, node_t *next);
void print_list(node_t *head);
void clean_list(node_t *head);

int main() {
    node_t *head = create_node(
        (void *)(intptr_t)1,
        create_node(
            (void *)(intptr_t)2,
            create_node((void *)(intptr_t)3,
                        create_node((void *)(intptr_t)4,
                                    create_node((void *)(intptr_t)5, NULL)))));

    print_list(head);

    clean_list(head);

    return 0;
}

node_t *create_node(void *val, node_t *next) {
    node_t *node = (node_t *)malloc(sizeof(node_t));

    node->val = val;
    node->next = next;

    return node;
}

void print_list(node_t *head) {
    node_t *current = head;

    while (current) {
        printf("%d \n", (int)(intptr_t)current->val);

        current = current->next;
    }
}

void clean_list(node_t *head) {
    node_t *current = head;

    while (current) {
        node_t *prev = current;
        current = current->next;

        // Because I know I'm just using ints I do not need to free val.
        free(prev);
    }
}
