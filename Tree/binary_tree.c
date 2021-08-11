#include "binary_tree.h"
#include "./Queue/queue.h"

BinaryTree* newTree(int elements, ...){

    // Elements specify the number of elements to be pushed into the tree.
    // Elements are added in level order
    BinaryTree* root = NULL;
    Queue *queue = newQueue();
    void *val;
    va_list ap;

    va_start(ap, elements);

    while(elements--){
        val = va_arg(ap, void*);

        if(root == NULL){
            root->data = val;
            root->left = NULL;
            root->right = NULL;
            enQueue(queue, root);
        }

        else{
            BinaryTree* parent = deQueue(queue);
            
        }
    }


}