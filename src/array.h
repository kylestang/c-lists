#include <stdint.h>

typedef struct {
    unsigned int capacity;
    unsigned int length;
    uint8_t* data;
    unsigned int dataSize;
} Array;

Array newArray(unsigned int dataSize);
void pushArray(Array* array, void* toPush);
void* popArray(Array* array, void* destination);
unsigned int lenArray(Array* array);
void freeArray(Array* array);
void* getArray(Array* array, unsigned int pos);
void* setArray(Array* array, unsigned int pos, void* value);
