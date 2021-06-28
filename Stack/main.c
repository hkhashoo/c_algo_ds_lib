#include <stdio.h>
#include <stdlib.h>
#define new(x) (x*)calloc(sizeof(x), 1)
typedef struct List{
	void* data;
	struct List *next;
}List;

typedef struct stack{
	struct List *top;
	int size;
}Stack;

Stack* newStack(){
	Stack *stack = new(Stack);
	return stack;
}

void push(Stack *stack, void *data){ //O(1) time
	struct List *newNode = new(List);
	newNode->data = data;
	newNode->next = NULL;
	
	if(stack->top == NULL){
		stack->top = newNode;
	}
	
	else{
		newNode->next = stack->top;
		stack->top = newNode;
	}
	stack->size++;
	
}

void* pop(Stack *stack){ //O(1) time
	
	if(stack->top){
		struct List *fNode = stack->top;
		void* data = fNode->data;
		stack->top = stack->top->next;
		free(fNode);
		stack->size--;
		return data;
	}
	
	return NULL;
	
}

Stack* reverseStack(Stack *stack ){ //O(n) time
	if(stack){
		Stack *s1 = newStack();
		List *iterator = stack->top;
		
		while(iterator){
			push(s1, iterator->data);
			iterator = iterator->next;
		}
		
		s1->size = stack->size;
		return s1;
	}
	
	return NULL;
	
}

void copyHelper(Stack *stack , List *iterator){
	if(iterator != NULL){
		copyHelper(stack, iterator->next);
		push(stack,iterator->data);
	}
}

Stack* copyStack(Stack *stack){ //O(n) time + O(n) space
	if(stack != NULL){
		Stack* s1 = newStack();
		copyHelper(s1,stack->top);
		s1->size = stack->size;
		return s1;
	}
	
	else return NULL;
	
}

int getSize(Stack *stack){
	return stack->size;
}