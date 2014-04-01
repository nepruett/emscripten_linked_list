#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED
#include "linked_list.h"

typedef void (*callback_t)(const char *message, struct Node *list);
callback_t SORT_CALLBACK;

extern void set_callback(callback_t f);
extern struct Node *naive_bubble_sort(struct Node *list);
extern struct Node *bubble_sort(struct Node *list);

#endif
