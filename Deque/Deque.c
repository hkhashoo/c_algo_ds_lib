#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Initialize the deque
Deque* newDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    if (!deque) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    deque->front = NULL;
    deque->rear = NULL;
    deque->length = 0;
    return deque;
}

// Add to the front
void pushFront(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (!deque->front) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    deque->length++;
}

// Add to the rear
void pushRear(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (!deque->rear) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    deque->length++;
}

// Remove from the front
int popFront(Deque* deque) {
    if (!deque->front) {
        printf("Deque is empty\n");
        return -1;
    }
    Node* temp = deque->front;
    int data = temp->data;
    deque->front = deque->front->next;
    if (deque->front) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL;
    }
    free(temp);
    deque->length--;
    return data;
}

// Remove from the rear
int popRear(Deque* deque) {
    if (!deque->rear) {
        printf("Deque is empty\n");
        return -1;
    }
    Node* temp = deque->rear;
    int data = temp->data;
    deque->rear = deque->rear->prev;
    if (deque->rear) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL;
    }
    free(temp);
    deque->length--;
    return data;
}

int getLength(Deque* deque) {
    return deque->length;
}

int peekRear(Deque* deque) {
    if (deque->rear) {
        return deque->rear->data;
    }
    printf("Deque is empty\n");
    return -1;
}

int peekFront(Deque* deque) {
    if (deque->front) {
        return deque->front->data;
    }
    printf("Deque is empty\n");
    return -1;
}

// Check if deque is empty
int isEmpty(Deque* deque) {
    return deque->length == 0 ? 1 : 0;
}

// Display the deque
void displayDeque(Deque* deque) {
    Node* current = deque->front;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the deque
void freeDeque(Deque* deque) {
    while (!isEmpty(deque)) {
        popFront(deque);
    }
    free(deque);
}
