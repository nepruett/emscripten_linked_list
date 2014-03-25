#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
    ./emcc
        src/c/linked_list.c
        -o build/js/linked_list.js
        -s EXPORTED_FUNCTIONS="['_ll_new_node', '_ll_value', '_ll_next', '_ll_add', '_ll_remove']"
*/
struct Node {
    struct Node *next;
    char *value;
};

extern struct Node *ll_new_node(char *value) {
    struct Node *node;
    node = malloc(sizeof(struct Node));
    char *copy = malloc(sizeof(value));
    strcpy(copy, value);
    node->value = copy;
    return node;
}

extern char *ll_value(struct Node *node) {
    if(node == NULL) return NULL;
    return node->value;
}

extern struct Node *ll_next(struct Node *node) {
    if(node == NULL) return NULL;
    return node->next;
}

struct Node *tail(struct Node *node) {
    if (node == NULL) return NULL;
    while (node->next != NULL) {
        node = node->next;
    }
    return node;
}

extern struct Node *ll_add(struct Node *root, char *value) {
    struct Node *node = ll_new_node(value);
    if (root == NULL) {
        root = node;
    } else {
        tail(root)->next = node;
    }
    return root;
}

extern struct Node *ll_remove(struct Node *root, char *value) {
    if (root == NULL) return NULL;
    if (root->value == value) {
        struct Node *next = root->next;
        free(root);
        return next;
    }
    struct Node *node = root;
    while(node->next != NULL) {
        if (strcmp(node->next->value, value) == 0) {
            struct Node *temp = node->next;
            node->next = temp->next;
            free(temp->value);
            free(temp);
            break;
        }
        node = node->next;
    }
    return root;
}

