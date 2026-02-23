#include "../include/linked_list.h"
#include <stdlib.h>
#include <stdio.h>

/* This function appends the given value at the end of the list
 *
 * @linkedPtr -> pointer to the linked_list that value sould be appended on
 * @value -> the given value that is going to get appeneded
 *
 * RETVALUES:
 *  success = LINKED_LIST_OK
 *  errror = any other ret code from the linked_list_error_t enum*/
linked_list_error_t linked_list_append(linked_list_t **linkedPtr,int value) {
    linked_list_t *newNode = malloc(sizeof(linked_list_t));
    if(!newNode) return LINKED_LIST_MEMORY_FAILURE;

    newNode->nodeValue = value;
    newNode->next = NULL;

    if(!*linkedPtr) {
        *linkedPtr = newNode;
        return LINKED_LIST_OK;
    }

    linked_list_t *temp = *linkedPtr;
    while(temp->next) 
        temp = temp->next;

    temp->next = newNode;
    return LINKED_LIST_OK;
}

/* This function appends th given value at the front of the list
 *
 * @linkedPtr -> pointer to the linked_list that the value is going to get append on
 * @value -> the given value that the function should append on the list
 *
 * RETVALUES:
 *  success = LINKED_LIST_OK
 *  error = any other ret code from the linked_list_error_t enum*/
linked_list_error_t linked_list_appendfront(linked_list_t **linkedPtr, int value) {
    linked_list_t *newNode = malloc(sizeof(linked_list_t));
    if(!newNode) return LINKED_LIST_MEMORY_FAILURE;

    newNode->nodeValue = value;
    newNode->next = *linkedPtr;

    if(!*linkedPtr) {
        *linkedPtr = newNode;
        return LINKED_LIST_OK;
    }
    
    *linkedPtr = newNode;
    return LINKED_LIST_OK;
}


/* This function removes the first node with value = to the given value
 *
 * @linkedPtr -> pointer to the linked list that we are going to remove the value
 * @value -> the given value that is going to be removed IF found
 *
 * RETVALUES:
 *  success = LINKED_LIST_OK
 *  error = any other ret code from the linked_list_error_t enum*/
linked_list_error_t linked_list_remove(linked_list_t **linkedPtr, int value) {
    if(!*linkedPtr) return LINKED_LIST_EMPTY;

    linked_list_t *temp = *linkedPtr, *prev = NULL;
    if(temp->nodeValue == value) {
        *linkedPtr = temp->next;
        free(temp);
        return LINKED_LIST_OK;
    }

    while(temp && temp->nodeValue != value) {
        prev = temp;
        temp = temp->next;
    }

    if(!temp) return LINKED_LIST_VALUE_NOT_FOUND;
    prev->next = temp->next;
    free(temp);

    return LINKED_LIST_OK;
}

/* This function removes the first node from the linked list
 *
 * @linkedPtr -> pointer to the given list that the function should remove the node
 *
 * RETVALUES:
 *  success = LINKED_LIST_OK
 *  error = any other ret code from the linked_list_error_t enum*/
linked_list_error_t linked_list_removefront(linked_list_t **linkedPtr) {
    if(!*linkedPtr) return LINKED_LIST_EMPTY;

    linked_list_t *temp = *linkedPtr;
    if(temp->next == NULL) {
        free(temp);
        *linkedPtr = NULL;
        return LINKED_LIST_OK;
    }

    *linkedPtr = temp->next;
    free(temp);

    return LINKED_LIST_OK;
}

/* This function prints all the nodes from the linked list
 *
 * @linkedPtr -> pointer to the linked list that the function should print its nodes
 *
 * RETVALUES:
 *  success = LINKED_LIST_OK
 *  error = any other ret code from the linked_list_error_t enum*/
linked_list_error_t linked_list_print(linked_list_t *linkedPtr) {
    if(!linkedPtr) return LINKED_LIST_EMPTY;

    while(linkedPtr) {
        printf("%d -> ",linkedPtr->nodeValue);
        linkedPtr = linkedPtr->next;
    }

    printf("NULL\n");
    return LINKED_LIST_OK;
}

/* This function destroys the linked_list and returns the memory back to the system
 *
 * @linkedPtr -> pointer to the linked list that the function should destroy
 *
 * RETVALUES:
 *  success = LINKED_LIST_OK
 *  error = any other ret code from the linked_list_error_t enum*/
linked_list_error_t linked_list_destroy(linked_list_t **linkedPtr) {
    if(!*linkedPtr) return LINKED_LIST_EMPTY;

    linked_list_t *temp = *linkedPtr;
    while(temp) {
        *linkedPtr = (*linkedPtr)->next;
        free(temp);
        temp = *linkedPtr;
    }

    *linkedPtr = NULL;
    return LINKED_LIST_OK;
}
