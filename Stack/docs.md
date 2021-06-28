# Stack data structure implemented using linked list

## Accepts pointer to a data type as store

The implementation of structure is as follows : 

* Container for void pointer

typedef struct List{
	void* data;
	struct List *next;
}List; 

* Stack structure

typedef struct stack{
	struct List *top;
	int size;
}Stack; 

### At no point does the library need you to instantiate these manually. There are functions for all necessary operations

1. Getting a stack object

    * Function : **newStack**()

        Description : Get a new stack object for performing operations
        Arguments : <None>
        Return Value : Stack*

    
2. Stack Operations

    * Function : **push**(*Stack`*`*, *void*)

        Description : Push a value to a stack object.
        Arguments : 

            1. Stack * : Pointer to the stack object where the data needs to be stored
            2. void *  : Pointer to the data object

        Return value : <None>
