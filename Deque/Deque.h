#define new (x) (x*) calloc(sizeof(x), 1)

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Deque {
    Node* front;
    Node* rear;
    int length;
} Deque;

Deque* newDeque();
void pushFront(Deque* deque, int data);
void pushRear(Deque* deque, int data);
int popFront(Deque* deque);
int popRear(Deque* deque);
int peekFront(Deque* deque);
int peekRear(Deque* deque);
int getLength(Deque* deque);
int isEmpty(Deque* deque);
void displayDeque(Deque* deque);
void freeDeque(Deque* deque);