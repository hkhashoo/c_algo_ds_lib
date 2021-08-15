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

    * Function : **void`*`** getData(*BinaryTree`*`*)

        Description : Gets the data of the node pointed by the argument node.

        Arguments : 

            1. Binary Tree * : Pointer to the binary tree object 

        Return value : *void`*`* Returns the void* address stored in the tree node.

    <br/><br/>

    * Function : **BinaryTree`*`** getLeft(*BinaryTree`*`*)

        Description : Gets the left subtree of the node pointed by the argument node.

        Arguments : 

            1. Binary Tree * : Pointer to the binary tree object 

        Return value : *BinaryTree`*`* Returns the root node of the left subtree. Returns NULL if left subtree is empty or root is empty.

    <br/><br/>

    * Function : **BinaryTree`*`** getRight(*BinaryTree`*`*)

        Description : Gets the right subtree of the node pointed by the argument node.

        Arguments : 

            1. Binary Tree * : Pointer to the binary tree object 

        Return value : *BinaryTree`*`* Returns the root node of the right subtree. Returns NULL if left subtree is empty or root is empty.

    <br/><br/>

    * Function : **int`*`** setData(*BinaryTree`*`*, *void`*`*)

        Description : Sets the value of data for the node pointed by the argument node.

        Arguments : 

            1. Binary Tree * : Pointer to the binary tree object 
            2. void* : Pointer to the generic type which needs to be fed in as data for the argument node.

        Return value : *int`*`* Returns the status of the set. Operation fails if argument node is NULL.

    <br/><br/>

    * Function : **int`*`** setLeft(*BinaryTree`*`*, *void`*`*)

        Description : Sets the value of data for the root of the left subtree of the node pointed by the argument node.

        Arguments : 

            1. Binary Tree * : Pointer to the binary tree object 
            2. void* : Pointer to the generic type which needs to be fed in as data for the argument node.

        Return value : *int`*`* Returns the status of the set. Operation fails if argument node is NULL or its left subtree is NULL.

    <br/><br/>

    * Function : **int`*`** setData(*BinaryTree`*`*, *void`*`*)

        Description : Sets the value of data for the root of the right subtree of the node pointed by the argument node.

        Arguments : 

            1. Binary Tree * : Pointer to the binary tree object 
            2. void* : Pointer to the generic type which needs to be fed in as data for the argument node.

        Return value : *int`*`* Returns the status of the set. Operation fails if argument node is NULL or its right subtree is NULL.

    <br/><br/>