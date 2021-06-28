#include <stdio.h>
#include <stdlib.h>
#include "main.c"

typedef struct Container{
	int data;
}Container;

void main(){
	Container c1;
	Container c2;
	Container c3;
	
	c1.data = 4;
	c2.data = 5;
	c3.data = 6;
	
	Queue *queue = newQueue();
	
	enQueue(queue, &c1);
	enQueue(queue, &c2);
	enQueue(queue, &c3);
	
	Queue *queue2 = reverseQueue(queue);

	while(!noQueue(queue2)){
		
		Container *catch = deQueue(queue2);
		printf("CAPTURED DATA : %d,  QUEUE LENGTH : %d\n", catch->data, queueLength(queue2));
	}
	
}