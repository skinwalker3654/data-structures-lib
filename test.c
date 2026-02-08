#include <stdio.h>
#include <unistd.h>
#include "include/vector.h"

int main(void) {
    vector_error_t error;
    vector_t *vector = NULL;

    error = vector_init(&vector);
    if(error == VECTOR_MEMORY_FAILURE) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    /* You can make the program safer by using error = FUNCTION and then If Else for every edge case
     * But its not really nessacery now. */
    printf("Test 1. Push values (10,20,30) into the vector...\n");
    vector_push(vector,10);
    vector_push(vector,20);
    vector_push(vector,30);
    printf("Test 1. passed\n\n");
    sleep(2);

    printf("Test 2. Pushfront value (5) into the vector...\n");
    vector_pushfront(vector,5);
    printf("Test 2. passed\n\n");
    sleep(2);

    printf("Test 3. Print the vector...\n");
    vector_print(vector);
    printf("Test 3. passed\n\n");
    sleep(2);

    printf("Test 4. Remove value (10) from the vector...\n");
    vector_erase(vector,10);
    printf("Test 4. passed\n\n");
    sleep(2);

    printf("Test 5. Remove first value from the vector...\n");
    vector_erasefront(vector);
    printf("Test 5. passed\n\n");
    sleep(2);

    printf("Test 6. Print the updated vector list...\n");
    vector_print(vector);
    printf("Test 6. passed\n\n");
    sleep(2);

    printf("Destroying the vector...\n");
    vector_destroy(&vector);
    printf("Program ended succesfully\n");

    return 0;
}
