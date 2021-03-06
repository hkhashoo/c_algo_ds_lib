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
    if(head == NULL) return;
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
    /*
    deletest the first occurance of a node with the given value;
    */
    LL *temp = *head;

    if(!myCompare((*head)->data, val)) *head = temp->next;
    else {
        LL *prev;

        while(myCompare(temp->data, val)) {
            if(temp == NULL) return 0;
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        temp->next = NULL;
    }
    free(temp);
    return 1;
}

int keyCount(int(*myCompare)(void*, void*), LL *head, void *val) {
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

int deleteIndex(LL **head, int elements, ...) {
    if(*head == NULL) return 0;
    /*
    NOTE : follows 0 based indexing;
    deletes the nodes at a particular index and returns the number of deleted nodes;
    */
    int val;
    va_list ap;
    int count = 0;
    int len = length(*head);

    va_start(ap, elements);

    while(elements--) {
        val = va_arg(ap, int) - count;

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

LL* search(int(*myCompare)(void*, void*), LL *head, void *val) {
    /*
    returns the pointer to the first instance of the given value, returns NULL if head is NULL or given value isn't found in the Linked List;
    */
    LL *temp = head;
    while(temp != NULL && myCompare(temp->data, val)) temp = temp->next;

    return temp;
}

LL **merge(int(*myCompare)(void*, void*), LL **arr, int alen, LL **brr, int blen) {

    LL **crr = malloc((alen + blen) * sizeof(LL*));
    int i = 0, j = 0, k = 0;
    
    while((i < alen) && (j < blen)) {
        if(myCompare(arr[i]->data, brr[j]->data) == 1) crr[k++] = arr[i++];
        else if(myCompare(arr[i]->data, brr[j]->data) == -1)crr[k++] = brr[j++];
        else {
            crr[k++] = brr[j++];
            crr[k++] = arr[i++];
        }
    }
    while(i < alen) crr[k++] = arr[i++];
    while(j < blen) crr[k++] = brr[j++];

    return crr;
}

LL **mergeSort(int(*myCompare)(void*, void*), LL **arr, int low, int high) {
    if(low == high) {
        LL* *element = malloc(sizeof(LL*));
        element[0] = arr[low];
        return element;
    }
    else return merge(myCompare, mergeSort(myCompare, arr, low, (low + high)/2), ((low + high)/2)-low+1, mergeSort(myCompare, arr, ((low + high)/2)+1, high), high-(((low + high)/2)+1)+1);
}

void sort(int(*myCompare)(void*, void*), LL **head) {
    if(*head == NULL) return;
    /*
    sorts LL using merge sort algo, uses 2 utility functions `mergeSort` and `merge`, both defined above;
    */
    int len = length(*head);
    LL **arr = malloc(len * sizeof(LL*));
    LL *temp = *head;
    int i = 0;
    
    while(temp != NULL) {
        arr[i++] = temp;
        temp = temp->next;
    }

    arr = mergeSort(myCompare, arr, 0, len-1);
    
    *head = arr[0];
    temp = *head;
    i = 1;

    while(i < len) {

        temp->next = arr[i++];
        temp = temp->next;
    }
    temp->next = NULL;
    return;
}

void reverse(LL **head) {
    if(*head == NULL || (*head)->next == NULL) return;
    /*
    reverses the given LL;
    */
    LL *temp = *head;
    LL *revHead;
    LL *revTemp;

    while(temp->next->next != NULL) temp = temp->next;
    revHead = temp->next;
    revTemp = revHead;
    temp->next = NULL;

    while((*head)->next != NULL) {
        temp = (*head)->next;
        while(temp->next != NULL && temp->next->next != NULL) temp = temp->next;

        if(temp->next == NULL) {
            revTemp->next = temp;
            (*head)->next = NULL;
        } else {
            revTemp->next = temp->next;
            temp->next = NULL;
        }
        revTemp = revTemp->next;
    }
    revTemp->next = *head;
    revTemp->next->next = NULL;
    *head = revHead;
    return;
}