#include <stdlib.h>
#include <stdarg.h>

typedef struct BinaryTree{
	void * data;
	struct BinaryTree *left;
	struct BinaryTree *right;
}BinaryTree;

BinaryTree* newBinaryTree(int, ...);
void preOrder(BinaryTree*, void (*f)(void*));
void inOrder(BinaryTree*, void (*f)(void*));
void postOrder(BinaryTree*, void (*f)(void*));
int height(BinaryTree*);
BinaryTree* getLeft(BinaryTree*);
BinaryTree* getRight(BinaryTree*);
void* getData(BinaryTree*);
int setLeft(BinaryTree*, void* data);
int setRight(BinaryTree*, void* data);
int setData(BinaryTree*, void* data);