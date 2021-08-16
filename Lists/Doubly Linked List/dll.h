#include <stdlib.h>
#include <stdarg.h>

typedef struct DLL {
    void *data;
    struct DLL *next;
    struct DLL *prev;
} DLL;

DLL* newDLL(int, ...);
void insertion(DLL*, void*);