#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Stack* newStack(){
	Stack *stack = new(Stack);
	return stack;
}

void push(Stack *stack, void *data){ //O(1) time
	struct StackContainer *newNode = new(StackContainer);
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
		struct StackContainer *fNode = stack->top;
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
		StackContainer *iterator = stack->top;
		
		while(iterator){
			push(s1, iterator->data);
			iterator = iterator->next;
		}
		
		s1->size = stack->size;
		return s1;
	}
	
	return NULL;
	
}

void copyHelper(Stack *stack , StackContainer *iterator){
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