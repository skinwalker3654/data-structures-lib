#include "../include/vector.h"
#include <stdlib.h>
#include <stdio.h>

/*This function initializes the given vector
 *
 * @vecPtr -> pointer to the given vector that the function will initialize
 * 
 * RETVALUES:
 *  success = VECTOR_OK
 *  error = any other ret code from the vector_error_t enum*/
vector_error_t vector_init(vector_t **vecPtr) {
    *vecPtr = malloc(sizeof(vector_t));
    if(!*vecPtr) return VECTOR_MEMORY_FAILURE;

    (*vecPtr)->capacity = 2;
    (*vecPtr)->counter = 0;

    (*vecPtr)->arrValues = malloc(sizeof(int)*(*vecPtr)->capacity);
    if(!vecPtr) {
        free(vecPtr);
        return VECTOR_MEMORY_FAILURE;
    }

    return VECTOR_OK;
}

/*This function pushes a value at the end of the given vector
 *
 * @vecPtr -> pointer to the vector that we gonna push the value
 * @value -> The value that is going to get pushed at the end of the vector
 *
 * RETVALUES:
 *  success = VECTOR_OK
 *  error = any other ret code from the vector_error_t enum*/
vector_error_t vector_push(vector_t *vecPtr, int value) {
    if(!vecPtr) return VECTOR_NO_MEMORY;
    if(vecPtr->counter >= vecPtr->capacity) {
        vecPtr->capacity *= 2;
        int *tempArr = realloc(vecPtr->arrValues,sizeof(int)*vecPtr->capacity);
        if(!tempArr) return VECTOR_MEMORY_FAILURE;

        vecPtr->arrValues = tempArr;
    }

    vecPtr->arrValues[vecPtr->counter] = value;
    vecPtr->counter++;

    return VECTOR_OK;
}

/*This function pushes a value at the start of the given vector
 *
 * @vecPtr -> pointer to the vector that we gonna push the value
 * @value -> The value that is going to get pushed at the start of the vector
 *
 * RETVALUES:
 *  success = VECTOR_OK
 *  error = any other ret code from the vector_error_t enum*/
vector_error_t vector_pushfront(vector_t *vecPtr, int value) {
    if(!vecPtr) return VECTOR_NO_MEMORY;
    if(vecPtr->counter >= vecPtr->capacity) {   
        vecPtr->capacity *= 2;
        int *tempArr = realloc(vecPtr->arrValues,sizeof(int)*vecPtr->capacity);
        if(!tempArr) return VECTOR_MEMORY_FAILURE;

        vecPtr->arrValues = tempArr;
    }

    if(vecPtr->counter == 0) {
        vecPtr->arrValues[0] = value;
        vecPtr->counter++;
        return VECTOR_OK;
    }

    for(int i=vecPtr->counter; i>0; i--)
        vecPtr->arrValues[i] = vecPtr->arrValues[i-1];

    vecPtr->arrValues[0] = value;
    vecPtr->counter++;

    return VECTOR_OK;
}

/*This function removes the first number that is equal to the given value, from the vector
 *
 * @vecPtr -> pointer to the vector that the function will remove the value
 * @value -> the value that is going to be deleted
 *
 * RETVALUES:
 *  success = VECTOR_OK
 *  error = any other ret code from the vector_error_t enum*/
vector_error_t vector_erase(vector_t *vecPtr, int value) {
    if(!vecPtr) return VECTOR_NO_MEMORY;
    if(vecPtr->counter == 0) return VECTOR_EMPTY;

    int foundValueIndex = -1;
    for(int i=0; i<vecPtr->counter; i++) {
        if(vecPtr->arrValues[i] == value) {
            foundValueIndex = i;
            break;
        }
    }

    if(foundValueIndex == -1) return VECTOR_VALUE_NOT_FOUND;

    for(int i=foundValueIndex; i<vecPtr->counter-1; i++) 
        vecPtr->arrValues[i] = vecPtr->arrValues[i+1];

    vecPtr->counter--;
    return VECTOR_OK;
}

/*This function removes the first number from the vector
 *
 * @vecPtr -> pointer to the vector that the function will remove the value
 *
 * RETVALUES:
 *  success = VECTOR_OK
 *  error = any other ret code from the vector_error_t enum*/
vector_error_t vector_erasefront(vector_t *vecPtr) {
    if(!vecPtr) return VECTOR_NO_MEMORY;
    if(vecPtr->counter == 0) return VECTOR_EMPTY;

    for(int i=0; i<vecPtr->counter-1; i++)
        vecPtr->arrValues[i] = vecPtr->arrValues[i+1];

    vecPtr->counter--;
    return VECTOR_OK;
}

/*This function prints every value inside the given vector
 *
 * @vecptr -> pointer to the vector that the function should print its values
 *
 * RETVALUES
 *  succes = VECTOR_OK
 *  error = eny other ret code from the vector_error_t enum*/
vector_error_t vector_print(vector_t *vecPtr) {
    if(!vecPtr) return VECTOR_NO_MEMORY;
    if(vecPtr->counter == 0) return VECTOR_EMPTY;
    
    if(vecPtr->counter == 1) {
        printf("[%d]\n",vecPtr->arrValues[0]);
        return VECTOR_OK;
    }

    printf("[%d",vecPtr->arrValues[0]);
    for(int i=1; i<vecPtr->counter; i++) 
        printf(", %d",vecPtr->arrValues[i]);
    printf("]\n");

    return VECTOR_OK;
}

/*This function releashes the taken memory for a vector back to the system
 *
 * @vecPtr -> pointer to the given vector that the function should free
 *
 * NOTE:
 *  make sure to always free the vector at the end 
 *  beacause if you forgot to do then Memory leaks are going to acour
 *
 * RETVALUES:
 *  success = VECTOR_OK
 *  error = any other ret code on from the vector_error_t enum*/
vector_error_t vector_destroy(vector_t **vecPtr) {
    if(!*vecPtr) return VECTOR_NO_MEMORY;
    if((*vecPtr)->counter == 0) {
        free(*vecPtr);
        return VECTOR_OK;
    }

    free((*vecPtr)->arrValues);
    (*vecPtr)->arrValues = NULL;

    free(*vecPtr);
    return VECTOR_OK;
}
