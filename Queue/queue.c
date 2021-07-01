#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* newQueue(){
	Queue *queue = new(Queue); //return a null queue object
	return queue;
}

void enQueue(Queue* queue, void *data){
	
	QueueContainer *newNode = new(QueueContainer);
	newNode->data = data;
	
	if(queue->rear == NULL) //First insertion to the queue
	{
		queue->rear = newNode;
		queue->front = newNode; 
	}
	
	else{
		newNode->next = queue->rear;
		queue->rear->prev = newNode;
		queue->rear = newNode;
	}
	
	queue->length += 1;
}

void* deQueue(Queue *queue){
	QueueContainer *fValue = queue->front;
	void *rValue = NULL;
	
	if(fValue) // If the queue does have an element left to dequeue
	{
		rValue = fValue->data;

		if(fValue->prev == NULL) // Only one element is left in the queue
		{
			queue->front = NULL;
			queue->rear = NULL;
		}

		else{
			queue->front->prev->next = NULL;
			queue->front = queue->front->prev;
		}

		queue->length -=1;
	}

	
	free(fValue);
	return rValue;
}

void* seeQueue(Queue *queue){
	if(queue->front) return queue->front->data;

	else return NULL;
}

int noQueue(Queue* queue){
	return (queue->rear == NULL);
}

int queueLength(Queue* queue){
	return queue->length;
}

Queue* reverseQueue(Queue* queue){

	Queue *reversequeue = newQueue();

	QueueContainer* iterator = queue->rear;

	while(iterator){
		enQueue(reversequeue, iterator->data);
		iterator = iterator->next;
	}

	return reversequeue;
}

Queue* copyQueue(Queue* queue){
	
	Queue * copyqueue = newQueue();

	QueueContainer* iterator = queue->front;

	while(iterator){
		enQueue(copyqueue, iterator->data);
		iterator = iterator->prev;
	}

	return copyqueue;
}