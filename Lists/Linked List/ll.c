#include "ll.h"

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
    /*
    insertion of a single element into the Linked List;
    */
    LL *temp = head;
    LL *newNode = malloc(sizeof(LL));
    
    newNode->data = val;
    newNode->next = NULL;

    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

int deleteKeys(int(*myCompare)(void*, void*), LL **head, int elements, ...) {
    if(*head == NULL) return 0;
    /*
    deletes all occurances of the given elements and returns number of nodes deleted successfully;
    */
    if(*head == NULL) return 0;
    
    void *val;
    va_list ap;
    int count = 0;

    va_start(ap, elements);

    while(elements--) {
        val = va_arg(ap, void*);
        int kc = keyCount(myCompare, *head, val);
        
        while(kc--) {
            if(delete(myCompare, head, val)) count++;
        }
    }
    return count;
}

int delete(int(*myCompare)(void*, void*), LL **head, void *val) {
    if(*head == NULL) return 0;

    LL *temp = *head;

    if(!myCompare((*head)->data, val)) *head = temp->next;
    else {
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

int length(LL *head) {
    /*
    returns length of the list, 0 for head == NULL;
    */
    LL *temp = head;
    int len = 0;

    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

int deleteIndex(int(*myCompare)(void*, void*), LL **head, int elements, ...) {
    if(*head == NULL) return 0;
    /*
    deletes the nodes at a particular index and returns the number of deleted nodes;
    NOTE : follows 0 based indexing;
    */
    int val;
    va_list ap;
    int count = 0;
    int len = length(*head);

    va_start(ap, elements);

    while(elements--) {
        val = va_arg(ap, int);

        if(val < len) {
            LL *temp = *head;

            if(!val) *head = temp->next;
            else {
                LL *prev;
                
                while(val--) {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = temp->next;
                temp->next = NULL;
            }
            free(temp);
            count++;
        }
    }
    return count;
}

int deleteLL(LL **head) {
    if(*head == NULL) return 0;
    /*
    deletes the Linked List and returns the number of elements deleted.
    */
    int count = 0;
    
    while((*head)->next != NULL) {    
        LL *temp = *head;
        
        while(temp->next->next != NULL) temp = temp->next;
        
        if(temp->next == NULL) {
            free(temp);
            (*head)->next = NULL;
        } else {
            free(temp->next);
            temp->next = NULL;
            count++;
        }
    }
    *head = NULL;
    
    return ++count;
}

LL* search(int (*myCompare)(void *, void *), LL *head, void *val) {
    if(head == NULL) return NULL;
}