#define new(x) (x*)calloc(sizeof(x), 1)
typedef struct StackContainer{
	void* data;
	struct StackContainer *next;
}StackContainer;

typedef struct stack{
	struct StackContainer *top;
	int size;
}Stack;

Stack* newStack();
void push(Stack *stack, void *data);
void* pop(Stack *stack);
Stack* reverseStack(Stack *stack );
Stack* copyStack(Stack *stack);
int getSize(Stack *stack);
