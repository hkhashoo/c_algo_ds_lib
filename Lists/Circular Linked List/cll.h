#include <stdlib.h>
#include <stdarg.h>

typedef struct CLL {
    void *data;
    struct CLL *next;
} CLL;

CLL* newCLL(int, ...);
void insertion(CLL*, void*);
void insertFront(CLL**, void*);
int deleteIndex(CLL**, int, ...);
int length(CLL*);
int deleteKeys(int (*)(void*, void*), CLL**, int, ...);
int keyCount(int (*)(void*, void*), CLL*, void*);
int delete(int (*)(void*, void*), CLL**, void*);
