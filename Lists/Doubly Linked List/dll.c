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

void insertFront(DLL **head, void *val) {
    DLL *newNode = malloc(sizeof(DLL));
    newNode->data = val;
    newNode->next = (*head);
    newNode->prev = NULL;

    (*head) = newNode;
    return;
}

void deleteFront(DLL **head) {
    DLL *temp = (*head);
    
    (*head) = (*head)->next;
    (*head)->prev = NULL;
    
    temp->next = NULL;
    free(temp);
    return;
}

int length(DLL *head) {
    DLL *temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

int deleteIndex(DLL **head, int elements, ...) {
    if(*head == NULL) return 0;
    /* 
    NOTE:- zero based indexing is followed.
    deletes the nodes at the given indices and returns the number of elements removed.
    */
    va_list ap;
    int val;
    int len = length(*head);
    int count = 0;

    va_start(ap, elements);

    while(elements--) {
        val = va_arg(ap, int) - count;
        
        if(val < len) {
            DLL *temp = *head;
            
            if(!val) *head = temp->next;
            else {
                DLL *papa = temp;
                
                while(val--) {
                    papa = temp;
                    temp = temp->next;
                }
                papa->next = temp->next;
                temp->prev = papa;
                temp->next = NULL;
                temp->prev = NULL;
            }
            free(temp);
            count++;
        }
    }
    return count;
}