#include <stdlib.h>
#include <stdarg.h>

typedef struct BST {
	void *data;
	struct BST *left;
	struct BST *right;
} BST;

BST* newBST(int (*)(void*, void*), int, ...);
void inOrder(BST*, void (*)(void*));
void preOrder(BST*, void (*)(void*));
void postOrder(BST*, void (*)(void*));
