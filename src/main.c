#include "array.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Array a = newArray(sizeof(int));

    int b = 0;
    int c = 1;
    int d = 2;
    pushArray(&a, &b);
    pushArray(&a, &c);
    pushArray(&a, &d);

    int z;
    popArray(&a, &z);
    int w = 13;

    pushArray (&a, &w);
    
    printf("2: %d\n", z);

    while (lenArray(&a) > 0) {
        int e;
        popArray(&a, &e);
        printf("%d\n", e);
    }

    freeArray(&a);

    List l = newList();

    int e = 5;
    char f = 'a';
    long long g = 9;

    pushList(&l, &e, sizeof(e));
    pushList(&l, &f, sizeof(f));
    pushList(&l, &g, sizeof(g));

    long long h;
    char i;
    int j;

    popList(&l, &h);
    popList(&l, &i);
    popList(&l, &j);

    printf("%ld\n", h);
    printf("%c\n", i);
    printf("%d\n", j);

    freeList(&l);
}
