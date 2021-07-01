# Stack data structure implemented using linked list

## Accepts pointer to a data type as store

The implementation of structure is as follows : 

* Container for void pointer

typedef struct StackContainer{
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
        
        Arguments : *None*
        
        Return Value : Stack*

    
2. Stack Operations

    * Function : **push**(*Stack`*`*, *void`*`*)

        Description : Push a value to a stack object.

        Arguments : 

            1. Stack * : Pointer to the stack object where the data needs to be stored
            2. void *  : Pointer to the data object

        Return value : *None*

    <br/><br/>

    * Function : **pop**(*Stack`*`*)

        Description : Remove the top-most element from the stack.

        Arguments : 

            1. Stack * : Pointer to the stack object 

        Return value : *void`*`* 
            Pointer to the topmost element of the stack
            If the stack is empty the return value would be NULL

    <br/><br/>

    * Function : **peek**(*Stack`*`*)

        Description : Get the top-most element from the stack without removing it

        Arguments : 

            1. Stack * : Pointer to the stack object 

        Return value : *void`*`* 
            Pointer to the topmost element of the stack
            If the stack is empty the return value would be NULL

    <br/><br/>

    * Function : **getSize**(*Stack`*`*)

        Description : Get the number of elements currently in the stack

        Arguments : 

            1. Stack * : Pointer to the stack object 

        Return value : *int* - Size of the stack as integer

    <br/><br/>

    * Function : **copyStack**(*Stack`*`*)

        Description : Copy contents of the arguments stack onto another stack

        Arguments : 

            1. Stack * : Pointer to the stack object 

        Return value : *Stack`*`* - Returns the copied stack

    <br/><br/>

    * Function : **reverseStack**(*Stack`*`*)

        Description : Reverse the contents of the arguments stack onto another stack (not in place)

        Arguments : 

            1. Stack * : Pointer to the stack object 

        Return value : *Stack`*`* - Returns the reversed stack
    
    <br/><br/>