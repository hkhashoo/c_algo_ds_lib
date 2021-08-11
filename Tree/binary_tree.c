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
                if(left){
                    parent->left = calloc(sizeof(BinaryTree),1);
                    parent->left->data = left;
                    enQueue(queue, parent->left);
                }

                else{
                    parent->left = NULL;
                    elements++;
                }

                if(right){
                    parent->right = calloc(sizeof(BinaryTree), 1);
                    parent->right->data = right;
                    enQueue(queue, parent->right);
                }

                else{
                    parent->right = NULL;
                    elements++;
                }
            }

            else{
                if(left){
                    parent->left = calloc(sizeof(BinaryTree), 1);
                    parent->left->data = left;
                    
                }

                else{
                    right = va_arg(ap, void*);
                    if(right){
                        parent->right = calloc(sizeof(BinaryTree), 1);
                        parent->right->data = right;
                    }

                    else{
                        elements++;
                    }
                }
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

int height(BinaryTree* root){

    if(root == NULL) return 0;

    Queue *queue = newQueue();
    BinaryTree *parent;
    int height = 0;
    int length = 1, added;
    enQueue(queue, root);

    while(length){
        added = 0;
        while(length--){
            parent = deQueue(queue);
            if(parent->left) {
                enQueue(queue, parent->left);
                added++;
            }
            if(parent->right){
                enQueue(queue, parent->right);
                added++;
            } 
        }

        length = added;
        height++;
    }

    return height;
}

void* getData(BinaryTree* root){
    
    if(!root) return NULL;

    return root->data;
}

BinaryTree* getLeft(BinaryTree *root){
    
    if(!root) return NULL;

    return root->left;
}

BinaryTree* getRight(BinaryTree* root){
    
    if(!root) return NULL;

    return root->right;
}

int setData(BinaryTree*root, void *data){
    if(!root) return 0;

    else root->data = data;

    return 1;
}

int setLeft(BinaryTree* root, void *data){
    
    if(!root) return 0;

    if(root->left){
        root->left->data = data;
    }

    else{
        root->left = calloc(sizeof(BinaryTree), 1);
        root->left->data = data;
    }

    return 1;
}

int setRight(BinaryTree* root, void *data){
    
    if(!root) return 0;
    
    if(root->right){
        root->right->data = data;
    }

    else{
        root->right = calloc(sizeof(BinaryTree), 1);
        root->right->data = data;
    }

    return 1;
}