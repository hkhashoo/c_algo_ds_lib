#include "bst.h"

void inorder(BST *root, void (*myPrint)(void*)) {
    if(root != NULL) {
        inorder(root->left, myPrint);
        myPrint(root->data);
        inorder(root->right, myPrint);
    }
}

BST* newBST(int (*myCompare)(void*, void*), int elements, ...) {
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
