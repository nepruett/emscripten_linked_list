#include <stdio.h>
#include <string.h>
#include "sorts.h"

/*
    ./emcc
    ~/IdeaProjects/emscripten_linked_list/src/c/linked_list.c
    ~/IdeaProjects/emscripten_linked_list/src/c/sorts.c
    -o ~/IdeaProjects/emscripten_linked_list/build/js/linked_list.js
    -s EXPORTED_FUNCTIONS="['_ll_new_node', '_ll_value', '_ll_next', '_ll_add', '_ll_remove', '_bubble_sort','_set_callback']"
    -s RESERVED_FUNCTION_POINTERS=1
*/

void set_callback(callback_t f)) {
    callback = f;
}

void safe_callback(const char *message, struct Node *list) {
    if(callback != NULL) {
        (*callback)(message, list);
    }
}

void swap(struct Node *a, struct Node *b)
{
    char *temp = a->value;
    a->value = b->value;
    b->value = temp;
}

struct Node *bubble_sort(struct Node *list) {
    printf("Doing BubbleSort!\n");
    (*callback)("callback message", list);

    int swapped;
    struct Node *temp;
    struct Node *last = NULL;

    /* Checking for empty list */
    if (list == NULL)
        return NULL;

    do {
        swapped = 0;
        temp = list;

        while (temp->next != last)
        {
            if (strcmp(temp->value, temp->next->value) > 0)
            {
                swap(temp, temp->next);
                swapped = 1;
            }
            temp = temp->next;
        }
        last = temp;
    } while (swapped);
    return list;
}
