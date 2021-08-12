#include <stdlib.h>
#include <stdarg.h>

typedef struct BST {
	void *data;
	struct BST *left;
	struct BST *right;
} BST;

BST* newBST(int (*)(void*, void*), void (*)(BST*, void*), int, ...);
void insertion (int (*)(void*, void*), BST*, void*);
void setData(BST*, void*);
void inOrder(BST*, void (*)(void*));
void preOrder(BST*, void (*)(void*));
void postOrder(BST*, void (*)(void*));
void insertOne(int (*)(void*, void*), void (*)(BST*, void*), BST*, void*);
void insertMany(int (*)(void*, void*), void (*)(BST*, void*), BST*, int, ...);
