#define new(x) (x*) calloc(sizeof(x), 1);
typedef struct QueueContainer{
	void* data;
	struct QueueContainer *next;
	struct QueueContainer *prev;
}QueueContainer;

typedef struct Queue{
	QueueContainer * rear;
	QueueContainer *front;
	int length;
}Queue;

Queue* newQueue();
void enQueue(Queue* queue, void *data);
Queue* copyQueue(Queue* queue);
Queue* reverseQueue(Queue* queue);
int queueLength(Queue* queue);
int noQueue(Queue* queue);
void* deQueue(Queue *queue);
void *seeQueue(Queue* queue);