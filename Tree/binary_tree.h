#include <stdlib.h>
#include <stdarg.h>

typedef struct BinaryTree{
	void * data;
	struct Tree *left;
	struct Tree *right;
}BinaryTree;

BinaryTree* newTree(int, ...);