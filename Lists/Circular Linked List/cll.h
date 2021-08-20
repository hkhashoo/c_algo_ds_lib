#include <stdlib.h>
#include <stdarg.h>

typedef struct CLL {
    void *data;
    struct CLL *next;
} CLL;

CLL* newCLL(int, ...);
void insertion(CLL*, void*);