#include "cll.h"
#include <stdio.h>

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

void insertFront(CLL **head, void *val) {
    CLL *newNode = malloc(sizeof(CLL));
    CLL *temp = *head;

    while(temp->next != *head) temp = temp->next;

    newNode->data = val;
    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

int deleteIndex(CLL **head, int elements, ...) {
    if(*head == NULL) return 0;
    /*
    NOTE:- zero based indexing is followed;
    removes the nodes at the given indices from the CLL and returns the number of elements removed;
    */
    va_list ap;
    int val;
    int len = length(*head);
    int count = 0;

    va_start(ap, elements);

    while(elements--) {
        val = va_arg(ap, int) - count;

        if(val < len) {
            CLL *del = *head;
            CLL *temp = *head;
            
            if(!val) {
                while(temp->next != *head) temp = temp->next;
                
                *head = (*head)->next;
            } else {
                while(val--) {
                    temp = del;
                    del = del->next;
                }
            }
            temp->next = del->next;
            del->next = NULL;
            free(del);
            count++;
        }
    }
    return count;
}

int length(CLL *head) {
    if(head == NULL) return 0;
    /*
    returns the length of the given CLL;
    */
    CLL *temp = head;
    int count = 0;

    while(temp->next != head) {
        count++;
        temp = temp->next;
    }
    return ++count;
}

int deleteKeys(int(*myCompare)(void*, void*), CLL **head, int elements, ...) {
    if(head == NULL) return 0;
    /*
    deletes all the nodes with the given keys and returns the number of keys deleted;
    */
    va_list ap;
    void *val;
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

int keyCount(int(*myCompare)(void*, void*), CLL *head, void *val) {
    if(head == NULL) return 0;
    /*
    returns the number of nodes containing a specific key;
    */
    CLL *temp = head;
    int count = 0;

    while(temp->next != head) {
        if(!myCompare(temp->data, val)) count++;
        temp = temp->next;
    }
    if(!myCompare(temp->data, val)) count++;

    return count;
}

int delete(int(*myCompare)(void*, void*), CLL **head, void *val) {
    if(head == NULL) return 0;
    /*
    deletes the first node with the given key value;
    */
    CLL *temp = (*head)->next;
    CLL *del = *head;

    if(!myCompare(del->data, val)) {
        while(temp->next != *head) temp = temp->next;
        temp->next = (*head)->next;
        *head = temp->next;
    } else {
        while(myCompare(temp->data, val)) {
            if(temp == *head) return 0;
            del = temp;
            temp = temp->next;
        }
        del->next = temp->next;
        del = temp;
    }
    del->next = NULL;
    if(del != NULL) free(del);

    return 1;
}