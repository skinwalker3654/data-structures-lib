#ifndef VECTOR_H
#define VECTOR_H

/* Vector Library Feb 7 2026 (C) by Skinwalker
 *
 * this is a library that uses vector data
 * structures and has many operations on that 
 * data structure.*/

/*The structure of the vector
 *
 * @arrValues -> An array of integers
 * @capacity -> An integer that contains the total integer size of the @arrValues
 * @counter -> An intger that holds the current slot that a value should be placed on
 *
 * NOTE:
 *  the @arrValues holds a size of 2 integers at first and whenever the counter
 *  increases by push values IF the @counter is >= @capacity then the capacity doubles its size
 *  and we reallocate more memory for the @arrValues*/

typedef struct vector_t {
    int *arrValues;
    int capacity;
    int counter;
} vector_t;

/*Returning error_codes
 *
 * This enum contains every returing code that operations return 
 * after their call*/
typedef enum vector_error_t {
    VECTOR_MEMORY_FAILURE,    
    VECTOR_EMPTY,
    VECTOR_VALUE_NOT_FOUND,
    VECTOR_NO_MEMORY,
    VECTOR_OK,
} vector_error_t;

/*+===================================================+/
 *+ OPERATIONS
 *+==================================================+*/
vector_error_t vector_init(vector_t **vecPtr);
vector_error_t vector_push(vector_t *vecPtr,int value);
vector_error_t vector_pushfront(vector_t *vecPtr,int value);
vector_error_t vector_erase(vector_t *vecPtr,int value);
vector_error_t vector_erasefront(vector_t *vecPtr);
vector_error_t vector_print(vector_t *vecPtr);
vector_error_t vector_destroy(vector_t **vecPtr);

#endif
