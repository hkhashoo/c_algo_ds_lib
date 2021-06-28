#include <stdio.h>
#include <stdlib.h>
#include "main.c"

typedef struct Integer{
	int data;
}Integer;

Integer* newInt(int data){
	Integer * i1 = malloc(sizeof(Integer));
	i1->data = data;
	return i1;
}

int to_integer(Integer* integer){
	return integer->data;
}

Integer* add(Integer *i1, Integer *i2){
	Integer *i3 = malloc(sizeof(Integer));
	i3->data	= i1->data + i2->data;
	return i3;
}

void populate(Integer* i, int data){
	i->data = data;
}

void main(){
	int n, data;
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	Stack *stack = newStack();
	
	for(int i=0; i<n; i++){
		scanf("%d", &data);
		Integer* i = newInt(data);
		push(stack , i);
	}

	while(getSize(stack)>=2){
		Integer *A = pop(stack);
		Integer *B = pop(stack);
		
		Integer *C = add(A, B);
		printf("%d + %d = %d\n", to_integer(A), to_integer(B), to_integer(C));
		
		push(stack , C);
	}
	
	printf("Stack Contents : %d", to_integer(pop(stack)));
	
}