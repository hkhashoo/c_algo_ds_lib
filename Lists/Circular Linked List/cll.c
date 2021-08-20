#include "cll.h"

CLL* newCLL(int elements, ...) {
    /*
    inserts all the elements and returns the first node's address;
    */
    va_list ap;
    void *val;
    CLL *head = NULL;
    CLL *temp = head;

    va_start(ap, elements);

    while(elements--) {
        val = va_arg(ap, void*);

        if(head == NULL) {
            head = malloc(sizeof(CLL));
            head->next = head;
            head->data = val;
        } else insertion(head, val);
    }    
    return head;
}

void insertion(CLL *head, void *val) {
    if(head == NULL) return;
    /*
    inserts the node with the given value into the CLL;
    */
    CLL *temp = head;
    CLL *newNode = malloc(sizeof(CLL));
    
    newNode->data = val;

    while(temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}