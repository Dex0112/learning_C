#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void pop(node_t **head) {
    node_t *next = (*head)->next;

    free(*head);

    *head = next;
}

void remove_val(node_t **head, int val) {
    node_t *prev = NULL;
    node_t *current = *head;

    if ((*head)->val == val) {
        pop(head);
        return;
    }

    while (current && current->val != val) {
        prev = current;
        current = current->next;
    }

    if (!current || current->val != val) {
        printf("Value %d not found in list\n", val);
        return;
    }

    prev->next = current->next;

    free(current);
}

void remove_by_index(node_t **head, int idx) {
    if (idx == 0) {
        pop(head);
        return;
    }

    node_t *current = *head;

    for (int i = 0; i < idx - 1; i++) {
        if (!current) {
            printf("Index: %d out of range!", idx);
            return;
        }

        current = current->next;
    }

    if (!current->next) {
        return;
    }

    node_t *new_next = current->next->next;

    free(current->next);

    current->next = new_next;
}

void pop_tail(node_t *head) {
    node_t *prev = NULL;
    node_t *current = head;

    while (current->next) {
        prev = current;
        current = current->next;
    }

    free(current);

    if (prev == NULL) {
        return;
    }

    prev->next = NULL;
}
void prepend_item(node_t **head, int val) {
    node_t *node = (node_t *)malloc(sizeof(node_t));

    node->val = val;

    node->next = *head;

    *head = node;
}

void append_item(node_t *head, int val) {
    node_t *current = head;

    while (current->next) {
        current = current->next;
    }

    current->next = (node_t *)malloc(sizeof(node_t));

    current->next->val = val;
    current->next->next = NULL;
}

void print_list(node_t *head) {
    node_t *current = head;

    while (current) {
        printf("Value: %d\n", current->val);

        current = current->next;
    }
}

void clean_list(node_t *head) {
    node_t *current = head;

    while (current) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    node_t *head = NULL;

    head = (node_t *)malloc(sizeof(node_t));

    if (head == NULL) {
        return 1;
    }

    head->next = (node_t *)malloc(sizeof(node_t));
    head->next->next = (node_t *)malloc(sizeof(node_t));
    head->next->next->next = (node_t *)malloc(sizeof(node_t));
    head->next->next->next->next = (node_t *)malloc(sizeof(node_t));
    head->next->next->next->next->next = NULL;

    head->val = 1;
    head->next->val = 2;
    head->next->next->val = 3;
    head->next->next->next->val = 4;
    head->next->next->next->next->val = 5;

    printf("Origin:\n");
    print_list(head);
    printf("New:\n");

    printf("Poping\n");
    pop(&head);

    printf("Poping Tail\n");
    pop_tail(head);

    printf("Appending 6\n");
    append_item(head, 6);

    printf("Prepending 0\n");
    prepend_item(&head, 0);

    printf("Removing value 7 (not present)\n");
    remove_val(&head, 7);

    printf("Removing value 3\n");
    remove_val(&head, 3);

    //remove_by_index(&head, 2);

    print_list(head);

    printf("Cleaning List\n");
    clean_list(head);

    return 0;
}
