#include <stdlib.h>
#include <stdarg.h>

typedef struct DLL {
    void *data;
    struct DLL *next;
    struct DLL *prev;
} DLL;

DLL* newDLL(int, ...);
void insertion(DLL*, void*);
void insertFront(DLL**, void*);
void deleteFront(DLL**);
int deleteIndex(DLL**, int, ...);
int length(DLL*);
int deleteKeys(int (*)(void*, void*), DLL**, int, ...);
int keyCount(int (*)(void*, void*), DLL*, void*);
int delete(int (*)(void*, void*), DLL**, void*);
DLL* search(int (*)(void*, void*), DLL*, void*);
int deleteDLL(DLL**);
void reverse(DLL**);
void sort(int (*)(void*, void*), DLL**);