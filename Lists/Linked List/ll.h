#include <stdlib.h>
#include <stdarg.h>

typedef struct LL {
    void *data;
    struct LL *next;
} LL;

LL* newLL(int, ...);
void insertion(LL*, void*);
//LL* getParent(LL*, LL*);
int deleteKeys(int (*)(void*, void*), LL*, int, ...);
int delete(int (*)(void*, void*), LL*, void*);
int keyCount(int (*)(void*, void*), LL*, void*);