#include "binary_tree.h"
#include "../Queue/queue.h"

BinaryTree* newBinaryTree(int elements, ...){

    // Elements specify the number of elements to be pushed into the tree.
    // Elements are added in level order

    BinaryTree* root = NULL;
    Queue* queue = newQueue();
    void *left, *right;
    va_list ap;

    va_start(ap, elements);

    while(elements--){
        left = va_arg(ap, void*);

        if(root == NULL){
            root = calloc(sizeof(BinaryTree), 1);
            root->data = left;
            enQueue(queue, root);
        }

        else{
            BinaryTree* parent = deQueue(queue);
            if(elements){ // there are more elements to be pushed left.
                elements--;
                right = va_arg(ap, void*);
                parent->left = calloc(sizeof(BinaryTree),1);
                parent->right = calloc(sizeof(BinaryTree), 1);
                parent->left->data = left;
                parent->right->data = right;
                enQueue(queue, parent->left);
                enQueue(queue, parent->right);
            }

            else{
                parent->left = calloc(sizeof(BinaryTree), 1);
                parent->left->data = left;
                break;
            }
        }
    }

    va_end(ap);
    return root;
}

void preOrder(BinaryTree *root, void (*print)(void*)){
    if(root){
        print(root->data);
        preOrder(root->left, print);
        preOrder(root->right, print);
    }
}

void inOrder(BinaryTree *root, void (*print)(void*)){
    if(root){
        inOrder(root->left, print);
        print(root->data);
        inOrder(root->right, print);
    }
}

void postOrder(BinaryTree *root, void (*print)(void*)){
    if(root){
        postOrder(root->left, print);
        postOrder(root->right, print);
        print(root->data);
    }
}