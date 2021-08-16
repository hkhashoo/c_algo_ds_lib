#include <stdlib.h>
#include <stdarg.h>

typedef struct LL {
    void *data;
    struct LL *next;
} LL;

LL* newLL(int, ...);
void insertion(LL*, void*);
int deleteKeys(int (*)(void*, void*), LL**, int, ...);
int delete(int (*)(void*, void*), LL**, void*);
int deleteIndex(LL**, int, ...);
int keyCount(int (*)(void*, void*), LL*, void*);
int length(LL*);
int deleteLL(LL**);
LL* search(int (*)(void*, void*), LL*, void*);
void sort(int (*)(void*, void*), LL**);
void reverse(LL**);