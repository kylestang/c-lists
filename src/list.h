#include <stdint.h>

typedef struct {
    int dataSize;
    uint8_t* value;
} ListEntry;

typedef struct {
    int capacity;
    int length;
    ListEntry* data;
} List;

List newList();
void pushList(List* list, void* value, int valueSize);
void* popList(List *list, void* destination);
void freeList(List *list);
