#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
struct Node {
    struct Node *next;
    char *value;
};
extern struct Node *ll_new_node(char *value);
extern char *ll_value(struct Node *node);
extern struct Node *ll_next(struct Node *node);
extern struct Node *ll_add(struct Node *root, char *value);
extern struct Node *ll_remove(struct Node *root, char *value);
#endif