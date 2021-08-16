#include "dll.h"

DLL* newDLL(int elements, ...) {
    /*
    creates a new DLL with the given elements and returns the pointer to the head;
    */
    DLL *head = NULL;
    void *val;
    va_list ap;

    va_start(ap, elements);

    while(elements--) {
        val = va_arg(ap, void*);

        if(head == NULL) {
            head = malloc(sizeof(DLL));
            head->data = val;
            head->next = NULL;
            head->prev = NULL;
        } else insertion(head, val);
    }
    return head;
}

void insertion(DLL *head, void *val) {
    /*
    insertion of a single element in the DLL;
    */
    DLL *temp = head;
    DLL *newNode = malloc(sizeof(DLL));
    
    newNode->data = val;
    newNode->next = NULL;

    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}