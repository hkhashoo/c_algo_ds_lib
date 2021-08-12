#include "bst.h"
#include <stdio.h>

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

void insertion(int(*myCompare)(void*, void*), BST *root, void *val) {
    BST *temp = root;
    BST *prev = temp;

    while(temp != NULL) {
        prev = temp;
        if(myCompare(temp->data, val)) temp = temp->right;
        else temp = temp->left;
    }
    BST *newNode = malloc(sizeof(BST));
    setData(newNode, val);
    newNode->left = NULL;
    newNode->right = NULL;

    if(myCompare(prev->data, val)) prev->right = newNode;
    else prev->left = newNode;
}

BST *newBST(int(*myCompare)(void*, void*), void(*setData)(BST*, void*), int elements, ...) {
    BST *root = NULL;
    void *val;
    va_list ap;

    va_start(ap, elements);

    while(elements--) {
        val = va_arg(ap, void*);

        if(root == NULL) {
            root = malloc(sizeof(BST));
            setData(root, val);
            root->right = NULL;
            root->left = NULL;
        } else insertion(myCompare, root, val);
    }
    return root;
}

void insertOne(int(*myCompare)(void*, void*), void(*setData)(BST*, void*), BST *root, void *data) {
    if(root != NULL) {
        BST *newNode = malloc(sizeof(BST));
        setData(newNode, data);

        insertion(myCompare, root, data);
    } else printf("ERR - root not assigned");
}

void insertMany(int(*myCompare)(void*, void*), void (*setData)(BST*, void*), BST *root, int elements, ...) {
    if(root != NULL) {
        void *val;
        va_list ap;

        va_start(ap, elements);

        while(elements--) {
            val = va_arg(ap, void*);

            insertOne(myCompare, setData, root, val);
        }
    } else printf("ERR - root not assigned");
}
