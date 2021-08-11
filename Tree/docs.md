# Binary Tree implementation

## Accepts pointer to a data type as store

The implementation of structure is as follows : 

* Tree structure

typedef struct BinaryTree{
	void * data;
	struct BinaryTree *left;
	struct BinaryTree *right;
}BinaryTree;

### At no point does the library need you to instantiate these manually. There are functions for all necessary operations

1. Getting a binary tree object

    * Function : **newBinaryTree**(*int, *...)

        Description : Get a new binary tree object for performing operations. This function will insert elements to the tree
        
        Arguments : 
            1. int : Number of elements to initially insert to the tree
            2. ... : Generic pointers to elements to insert
        
        Return Value : BinaryTree*

        Note : 
            Elements will be inserted LEVEL ORDER wise

    
2. Binary Tree Operations

    * Function : **preOrder**(*BinaryTree`*`*, *void (`*`f)(void`*`)*)

        Description : Prints the elements in preOrder

        Arguments : 

            1. Binary Tree * : Pointer to the binary tree object which needs to be printed in preorder
            2. void (*f)(void *)  : Print function which is able to print the generic type. (The storage unit)

        Return value : *None*

    <br/><br/>

    * Function : **inOrder**(*BinaryTree`*`*, *void (`*`f)(void`*`)*)

        Description : Prints the elements in inOrder

        Arguments : 

            1. Binary Tree * : Pointer to the binary tree object which needs to be printed in inorder
            2. void (*f)(void *)  : Print function which is able to print the generic type. (The storage unit)

        Return value : *None*

    <br/><br/>

    * Function : **postOrder**(*BinaryTree`*`*, *void (`*`f)(void`*`)*)

        Description : Prints the elements in postOrder

        Arguments : 

            1. Binary Tree * : Pointer to the binary tree object which needs to be printed in preorder
            2. void (*f)(void *)  : Print function which is able to print the generic type. (The storage unit)

        Return value : *None*

    <br/><br/>