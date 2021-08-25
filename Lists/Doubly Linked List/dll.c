#include "dll.h"

DLL* newDLL(int elements, ...) {
    /*
    creates a new DLL with the given elements and returns the addess of the first node;
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
    if(head == NULL) return;
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
    NOTE:- zero based indexing is followed;
    deletes the nodes at the given indices and returns the number of elements removed;
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
                while(val--) {
                    temp = temp->next;
                }
                DLL *papa = temp->prev;

                papa->next = temp->next;
                if(temp->next != NULL) temp->next->prev = papa;
                temp->next = NULL;
                temp->prev = NULL;
            }
            free(temp);
            count++;
        }
    }
    return count;
}

int deleteKeys(int(*myCompare)(void*, void*), DLL **head, int elements, ...) {
    if(*head == NULL) return 0;
    /*
    deletes all nodes with the given keys in them and returns number of nodes deleted successfully;
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

int keyCount(int(*myCompare)(void*, void*), DLL *head, void *val) {
    /*
    returns the number of elements with a given value;
    */
    DLL *temp = head;
    int kc = 0;

    while(temp != NULL) {
        if(!myCompare(temp->data, val)) kc++;
        temp = temp->next;
    }
    return kc;
}

int delete(int(*myCompare)(void*, void*), DLL **head, void *val) {
    if(*head == NULL) return 0;
    /*
    deletest the first occurance of a node with the given value;
    */
    DLL *temp = *head;

    if(!myCompare((*head)->data, val)) *head = temp->next;
    else {
        while(myCompare(temp->data, val)) {
            if(temp == NULL) return 0;
            temp = temp->next;
        }
        DLL *prev = temp->prev;
        
        prev->next = temp->next;
        if(temp->next->prev != NULL) temp->next->prev = prev;
        temp->next = NULL;
        temp->prev = NULL;
    }
    free(temp);
    return 1;
}

DLL* search(int(*myCompare)(void*, void*), DLL *head, void *val) {
    if(head == NULL) return NULL;
    /*
    checks for a given value in the list and returns a pointer to that node;
    */
    DLL *temp = head;
    
    while(temp != NULL && myCompare(temp->data, val)) temp = temp->next;
    return temp;
}

int deleteDLL(DLL **head) {
    if(*head == NULL) return 0;
    /*
    deletes the entire DLL and returns the number of nodes deleted;
    */    
    int count = 0;
    DLL *temp = *head;

    while(temp->next != NULL) temp = temp->next;

    while(temp != *head) {
        DLL *prev = temp->prev;
        
        prev->next = NULL;
        temp->prev = NULL;
        free(temp);
        temp = prev;
        count++;
    }
    *head = NULL;
    
    return ++count;
}

void reverse(DLL **head) {
    if(*head == NULL) return;
    /* 
    reverses the given DLL;
    */
    DLL *temp = *head;
    
    while(temp->next != NULL) temp = temp->next;
    *head = temp;
    DLL *prev = temp->prev;
    
    while(temp != NULL) {
        temp->prev = temp->next;
        temp->next = prev;
        temp = prev;
        if(temp != NULL) prev = temp->prev;
    }
    return;
}

int partition(int(*myCompare)(void*, void*), DLL **arr, int low, int high) {
    int i = low + 1, j = high;
    
    while(i < j) {
        while(myCompare(arr[i]->data, arr[low]->data) != -1 && i <= high) i++;
        while(myCompare(arr[j]->data, arr[low]->data) != 1 && j > low)  j--;

        if(i < j) {
            DLL *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    if(j != low) {
        DLL *temp = arr[j];
        arr[j] = arr[low];
        arr[low] = temp;
    }
    return j;
}

void quickSort(int(*myCompare)(void *, void *), DLL **arr, int low, int high) {
    if(low < high) {
        int j = partition(myCompare, arr, low, high);
        quickSort(myCompare, arr, low, j-1);
        quickSort(myCompare, arr, j+1, high);
    }
}

void sort(int(*myCompare)(void*, void*), DLL **head) {
    if(*head == NULL) return;
    /*
    sorts the given DLL;
    */
    int len = length(*head);
    DLL **arr = malloc(len * sizeof(DLL*));
    int i = 0;
    DLL *temp = *head;

    while(temp != NULL) {
        arr[i++] = temp;
        temp = temp->next;
    }
    quickSort(myCompare, arr, 0, len - 1);

    *head = arr[0];
    i = 1;
    temp = *head;
    temp->prev = NULL;

    while(i < len) {
        temp->next = arr[i];
        temp = temp->next;
        temp->prev = arr[i-1];
        i++;
    }
    temp->next = NULL;
    return;
}