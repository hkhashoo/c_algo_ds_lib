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

BST* getParent(int(*myCompare)(void*, void*), BST *root, BST *valNode) {
    if(valNode == root || valNode == NULL) return NULL;
    BST *temp = root;
    BST *prev;

    while(temp != valNode && temp != NULL) {
        prev = temp;
        if(myCompare(temp->data, valNode->data) == 1) temp = temp->right;
        else temp = temp->left;
    }
    return prev;
}

void insertion(int(*myCompare)(void*, void*), BST *root, void *val) {
    BST *newNode = malloc(sizeof(BST));
    setData(newNode, val);
    newNode->left = NULL;
    newNode->right = NULL;

    BST *prev = getParent(myCompare, root, newNode);
    
    if(myCompare(prev->data, val) == 1) prev->right = newNode;
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

int insertOne(int(*myCompare)(void*, void*), void(*setData)(BST*, void*), BST *root, void *data) {
    /*
    returns 1 for successful insertion, 0 for unsuccessful insertion;
    */
    if(root != NULL) {
        BST *newNode = malloc(sizeof(BST));
        setData(newNode, data);

        insertion(myCompare, root, data);
        return 1;
    } else return 0;
}

int insertMany(int(*myCompare)(void*, void*), void(*setData)(BST*, void*), BST *root, int elements, ...) {
    /*
    returns 1 for successful insertion, 0 for unsuccessful insertion;
    */
   if(root != NULL) {
        void *val;
        va_list ap;

        va_start(ap, elements);

        while(elements--) {
            val = va_arg(ap, void*);

            insertOne(myCompare, setData, root, val);
        } 
        return 1;
    } else return 0;
}

BST* search(int(*myCompare)(void*, void*), BST *root, void *data) {
    /* 
    returns the pointer to the node which has the desired value, else returns NULL;
    */
    BST *temp = root;
    while(temp != NULL) {
        if(myCompare(temp->data, data) == 1) temp = temp->right;
        else if(myCompare(temp->data, data) == -1) temp = temp->left;
        else break;
    }
    return temp;
}

BST* inOrderSuccessor(BST *node) {
    BST *successor = node->right;

    while(successor->left != NULL) successor = successor->left;
    return successor;
}

BST* delete(int(*myCompare)(void*, void*), BST *root, void *data) {
    /*
    returns root node for a successful deletion, NULL for a failed deletion;
    CASES OF FAILED DELETION :- 
        -> data value doesnt exist in the tree;
        -> tree hasn't been initialized;
    */
    BST *searched = search(myCompare, root, data);
    
    if(root == NULL) return NULL;
    if(searched == NULL) return NULL;
    else {
        BST *papa = getParent(myCompare, root, searched);
        if(searched->left == NULL && searched->right == NULL) {
            if(papa != NULL) {
                if(papa->left == searched) papa->left = NULL;
                else papa->right = NULL;
            } else root = NULL;
        } else if(searched->right != NULL && searched->left == NULL) {
            if(papa != NULL) {
                if(papa->right == searched) papa->right = searched->right;
                else papa->left = searched->right;
            } else root = searched->right;
        } else if(searched->left != NULL && searched->right == NULL) {
            if(papa != NULL) {
                if(papa->right == searched) papa->right = searched->left;
                else papa->left = searched->left;
            } else root = searched->left;
        } else {
            BST *successor = inOrderSuccessor(searched);
            BST *successorPapa = getParent(myCompare, root, successor);
            successorPapa->left = successor->right;

            if(papa != NULL) {
                if(papa->left == searched) papa->left = successorPapa->left;
                else papa->right = successor;
            } else root = successor;
            successor->right = searched->right;
            successor->left = searched->left;
            searched->left = NULL;
            searched->right = NULL;
        }
        free(searched);
        return root;
    }
}
