#include "list.h"
#include <stdlib.h>

List newList() {
    List new = {0, 0, 0};
    return new;
}

// Data is copied and owned by the list. The memory at 'value' may be dropped
void pushList(List* list, void* value, int valueSize) {
    if (list->capacity == 0) {
        list->data = reallocarray(NULL, 1, sizeof(ListEntry));
        list->capacity = 1;
    }

    if (list->capacity == list->length) {
        list->data = reallocarray(list->data, list->length * 2, sizeof(ListEntry));
        list->capacity *= 2;
    }

    uint8_t* entryData = malloc(valueSize);
    for (int i = 0; i < valueSize; i++) {
        entryData[i] = ((uint8_t*) value)[i];
    }
    ListEntry newEntry = {valueSize, entryData};

    list->data[list->length] = newEntry;
    list->length += 1;
}

// Pops a value from the array and stores it in destination. Returns NULL if the array is empty.
// The caller must ensure that destination has enough memory to store the popped value.
void* popList(List *list, void* destination) {
    if (list->length == 0) {
        return NULL;
    }

    list->length -= 1;

    ListEntry *toPop = &(list->data[list->length]);

    for (int i = 0; i < toPop->dataSize; i++) {
        ((uint8_t *) destination)[i] = toPop->value[i];
    }

    free(toPop->value);
    
    return destination;
}

void freeList(List *list) {
    for (int i = 0; i < list->length; i++) {
        free(list->data[i].value);
    }

    free(list->data);
}
