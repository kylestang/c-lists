#include "array.h"
#include <stdlib.h>

// A generic array type
Array newArray(unsigned int dataSize) {
    Array new = {
        0,
        0,
        NULL,
        dataSize
    };

    return new;
}

// Pushes the value at toPush to the array by copying memory.
// The original memory may be freed by the owner.
void pushArray(Array* array, void* toPush) {
    if (array->capacity == 0) {
        array->data = reallocarray(NULL, 1, array->dataSize);
        array->capacity += 1;
    }

    if (array->length == array->capacity) {
        array->data = reallocarray(array->data, array->capacity * 2, array->dataSize);
        array->capacity *= 2;
    }

    int index = array->dataSize * array->length;
    for (int i = 0; i < array->dataSize; i++) {
        array->data[index + i] = ((uint8_t*) toPush)[i];
    }

    array->length += 1;    
}

// Pops a value from the array and stores it in destination. Returns NULL if the array is empty.
// The caller must ensure that destination has enough memory to store the popped value.
void* popArray(Array* array, void* destination) {
    if (array->length == 0) {
        return NULL;
    }

    array->length -= 1;

    for (int i = 0; i < array->dataSize; i++) {
        ((uint8_t*) destination)[i] = array->data[array->dataSize * array->length + i];
    }

    return destination;
}

// Returns a pointer to the value at pos, or NULL if pos is longer than the array
void* getArray(Array* array, unsigned int pos) {
    if (pos >= array->length) {
        return NULL;
    }

    return (void*) array->data + (array->dataSize * pos);
}

// Sets the value at pos to the provided value.
// Returns a pointer to the value in the array, or NULL if pos is larger than the array length
void* setArray(Array* array, unsigned int pos, void* value) {
    if (pos >= array->length) {
        return NULL;
    }

    int index = array->dataSize * pos;
    for (int i = 0; i < array->dataSize; i++) {
        array->data[index + i] = ((uint8_t*) value)[i];
    }

    return array->data + index;
}

// Returns the length of the array
unsigned int lenArray(Array* array) {
    return array->length;
}

// Frees all data in the array.
// The object itself may be reused.
void freeArray(Array* array) {
    free(array->data);
    array->data = NULL;
    array->length = 0;
    array->capacity = 0;
    array->dataSize = 0;
}
