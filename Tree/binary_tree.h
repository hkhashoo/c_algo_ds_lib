#include <stdlib.h>
#include <stdarg.h>

typedef struct Tree{
	void * data;
	struct Tree *left;
	struct Tree *right;
}

void newTree(void*, ...);