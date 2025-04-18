# Queue data structure implemented using doubly linked list

## Accepts pointer to a data type as store

The implementation of structure is as follows : 

* Container for void pointer
```
typedef struct QueueContainer{
	void* data;
	struct QueueContainer *next;
	struct QueueContainer *prev;
}QueueContainer;
```
<br></br>
* Stack structure
```
typedef struct Queue{
	QueueContainer * rear;
	QueueContainer *front;
	int length;
}Queue;
```
### At no point does the library need you to instantiate these manually. There are functions for all necessary operations

1. Getting a queue object

    * Function : **newQueue**()

        Description : Get a new queue object for performing operations
        
        Arguments : *None*
        
        Return Value : Queue*

    
2. Stack Operations

    * Function : **enQueue**(*Queue`*`*, *void`*`*)

        Description : Add an element to the rear end of the queue.

        Arguments : 

            1. Queue * : Pointer to the queue object where the data needs to be stored
            2. void *  : Pointer to the data object

        Return value : *None*

    <br/><br/>

    * Function : **deQueue**(*Queue`*`*)

        Description : Remove and return the element at the front end of the Queue.

        Arguments : 

            1. Queue * : Pointer to the queue object 

        Return value : *void`*`* 
            Pointer to the element at the front of the Queue
            If the queue is empty the return value would be NULL

    <br/><br/>

    * Function : **seeQueue**(*Queue`*`*)

        Description : Get the element at the front end of the queue without removing it.

        Arguments : 

            1. Queue * : Pointer to the queue object 

        Return value : *void`*`* 
            Pointer to the element at the front end of the queue.
            If the queue is empty the return value would be NULL

    <br/><br/>

    * Function : **queueLength**(*Queue`*`*)

        Description : Get the number of elements currently in the queue

        Arguments : 

            1. Queue * : Pointer to the stack object 

        Return value : *int* - Length of the queue as integer

    <br/><br/>

    * Function : **copyQueue**(*Queue`*`*)

        Description : Copy contents of the argument queue onto another queue

        Arguments : 

            1. Queue * : Pointer to the queue object 

        Return value : *Queue`*`* - Returns the copied stack

    <br/><br/>

    * Function : **reverseQueue**(*Queue`*`*)

        Description : Reverse the contents of the arguments queue onto another queue (not in place)

        Arguments : 

            1. Queue * : Pointer to the queue object 

        Return value : *Queue`*`* - Returns the reversed stack
    
    <br/><br/>