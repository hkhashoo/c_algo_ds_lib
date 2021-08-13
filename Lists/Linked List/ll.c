#include "ll.h"

/*LL* getParent(int(*myCompare)(void*, void*), LL *head, LL *newNode) {
    LL *temp = head;
    LL *prev;

    while(temp != newNode && temp != NULL) {
        prev = temp;
        temp = temp->next;
    }
}*/

LL* newLL(int elements, ...) {
    /*
    insertion of multiple elements in the list;
    */
    LL *head = NULL;
    void *val;
    va_list ap;

    va_start(ap, elements);

    while(elements--) {
        val = va_arg(ap, void*);

        if(head == NULL) {
            head = malloc(sizeof(LL));
            head->data = val;
            head->next = NULL;
        } else insertion(head, val);
    }
    return head;
}

void insertion(LL *head, void *val) {
    LL *temp = head;
    LL *newNode = malloc(sizeof(LL));
    
    newNode->data = val;
    newNode->next = NULL;

    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

int deleteKeys(int(*myCompare)(void*, void*), LL *head, int elements, ...) {
    /*
    deletes all occurances of the given elements and returns number of nodes deleted successfully;
    */
    if(head == NULL) return 0;
    
    void *val;
    va_list ap;
    int count = 0;
    int kc = keyCount(myCompare, head, val);

    va_start(ap, elements);

    while(elements--) {
        val = va_arg(ap, void*);
        while(kc--) {
            if(delete(myCompare, head, val)) count++;
        }
    }
    return count;
}

int delete(int(*myCompare)(void*, void*), LL *head, void *val) {
    LL *temp = head;

    if(!myCompare(head->data, val)) {
        head = temp->next;
        temp->next = NULL;
    } else {
        LL *prev;

        while(myCompare(temp->data, val)) {
            if(temp == NULL) return 0;
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        prev->next = temp->next;
        temp->next = NULL;
    }
    free(temp);
    return 1;
}

int keyCount(int (*myCompare)(void*, void*), LL *head, void *val) {
    /*
    returns the numbers of occurances of a key in the list;
    */
    int count = 0;
    LL *temp = head;

    while(temp != NULL) {
        if(!myCompare(temp->data, val)) count++;
        temp = temp->next;
    }
    return count;
}