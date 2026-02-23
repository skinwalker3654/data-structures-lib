#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* Linked List Library Feb 23 2026 (C) by skinwalker
 * 
 * this is a library that uses 
 * linked list data structures and has
 * many operations on that data structure.*/

/* The structure of the linked list
 *
 * @nodeValue -> the value that every node has
 * @next -> pointer to the next node
 *
 * NOTE:
 *  A node points to other node and that other node points to another
 *  till one node points to NULL*/
typedef struct linked_list_t {
    int nodeValue;
    struct linked_list_t *next;
} linked_list_t;

/* Returning error_codes
 *
 * This enum contains every returning code that the operations
 * return after their call*/
typedef enum linked_list_error_t {
    LINKED_LIST_MEMORY_FAILURE,
    LINKED_LIST_EMPTY,
    LINKED_LIST_VALUE_NOT_FOUND,
    LINKED_LIST_OK,
} linked_list_error_t;

/*+=========================================================+/
 *+ OPERATIONS
 *+=========================================================+*/
linked_list_error_t linked_list_append(linked_list_t **linkedPtr,int value);
linked_list_error_t linked_list_appendfront(linked_list_t **linkedPtr,int value);
linked_list_error_t linked_list_remove(linked_list_t **linkedPtr,int value);
linked_list_error_t linked_list_removefront(linked_list_t **linkedPtr);
linked_list_error_t linked_list_print(linked_list_t *linkedPtr);
linked_list_error_t linked_list_destroy(linked_list_t **linkedPtr);

#endif
