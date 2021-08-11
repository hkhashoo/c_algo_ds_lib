#include "bst.h"

void inOrder(BST *root, void (*myPrint)(void*)) {
    if(root != NULL) {
        inOrder(root->left, myPrint);
        myPrint(root->data);
        inOrder(root->right, myPrint);
    }
}

void postOrder(BST *root, void (*myPrint)(void*)) {
    if(root != NULL) {
        postOrder(root->left, myPrint);
        postOrder(root->right, myPrint);
        myPrint(root->data);
    }
}

void preOrder(BST *root, void (*myPrint)(void*)) {
    if(root != NULL) {
        myPrint(root->data);
        preOrder(root->left, myPrint);
        preOrder(root->right, myPrint);
    }
}

BST *newBST(int (*myCompare)(void*, void*), int elements, ...) {
    BST *root = NULL;
    void *val;
    va_list ap;

    va_start(ap, elements);

    while(elements--) {
        val = va_arg(ap, void*);

        if(root == NULL) {
            root = malloc(sizeof(BST));
            root->data = val;
            root->right = NULL;
            root->left = NULL;
        } else {
            BST *temp = root;
            BST *prev = temp;

            while(temp != NULL) {
                prev = temp;
                if(myCompare(root->left, val)) temp = temp->right;
                else temp = temp->left;
            }
            BST *newNode = malloc(sizeof(BST));
            newNode->data = val;
            newNode->left = NULL;
            newNode->right = NULL;

            if(myCompare(root->left, val)) prev->right = newNode;
            else prev->left = newNode;
        }
    }
    return root;
}
