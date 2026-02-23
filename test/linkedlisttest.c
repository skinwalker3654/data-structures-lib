#include <stdio.h>
#include <unistd.h>
#include "../include/linked_list.h"

int main(void) {
    linked_list_t *list = NULL;

    /* You can make the program safer by using error = FUNCTION and then If Else for every edge case
     * But its not really nessacery now. */
    printf("Test 1. Append the values (10,20,30) into the linked list...\n");
    linked_list_append(&list,10);
    linked_list_append(&list,20);
    linked_list_append(&list,30);
    printf("Test 1. passed\n\n");
    sleep(2);
    
    printf("Test 2. Appendfront the value (5) into the linked list...\n");
    linked_list_appendfront(&list,5);
    printf("Test 2. passed\n\n");
    sleep(2);

    printf("Test 3. Print the linked list...\n");
    linked_list_print(list);
    printf("Test 3. passed\n\n");
    sleep(2);

    printf("Test 4. Remove the value (10) from the linked list...\n");
    linked_list_remove(&list,10);
    printf("Test 4. passed\n\n");
    sleep(2);

    printf("Test 5. Remove the first value from the linked list...\n");
    linked_list_removefront(&list);
    printf("Test 5. passed\n\n");
    sleep(2);

    printf("Test 6. Print the updated linked list...\n");
    linked_list_print(list);
    printf("Test 6. passed\n\n");
    sleep(2);

    printf("Destroying the linked list...\n");
    linked_list_destroy(&list);
    printf("Program has been ended succesfully\n");

    return 0;
}
