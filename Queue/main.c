#include <stdio.h>
#include <stdlib.h>
#define new(x) (x*) calloc(sizeof(x), 1);
typedef struct list{
	void* data;
	struct list *next;
}List;

typedef struct Queue{
	List * rear;
	int length;
}Queue;

Queue* newQueue(){
	Queue *queue = new(Queue);
	return queue;
}

void enQueue(Queue* queue, void *data){
	
	List *newNode = new(List);
	newNode->data = data;
	
	if(queue->rear == NULL) //First insertion to the queue
	{
		queue->rear = newNode;
	}
	
	else{
		newNode->next = queue->rear;
		queue->rear = newNode;
	}
	
	queue->length += 1;
}

void* deQueue(Queue *queue){
	List *fValue = queue->rear;
	List *pValue = NULL;
	void *rValue = NULL;
	
	if(fValue){
		while(fValue->next){
			pValue = fValue;
			fValue = fValue->next;
		}
		rValue = fValue->data;
	}
	if(pValue){
		pValue->next = NULL;
		queue->length--;
	}
		
	else{
		queue->rear = NULL;
		queue->length = 0;
	}
	
	free(fValue);
	return rValue;
}

int noQueue(Queue* queue){
	return (queue->rear == NULL);
}

int queueLength(Queue* queue){
	return queue->length;
}

Queue* reverseQueue(Queue* queue){
	
	if(queue == NULL){
		printf("NULL QUEUE\n");
		return NULL;
	}
	Queue *newQ = newQueue();
	List *iterator = queue->rear;
	
	while(iterator){
		enQueue(newQ, iterator->data);
		iterator = iterator->next;
	}
	
	return newQ;
}

Queue* copyQueue(Queue* queue){
	
	Queue * q1 = reverseQueue(queue);
	q1 = reverseQueue(q1);
	
	return q1;
}