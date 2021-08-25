#include <stdio.h>
#include <stdlib.h>

/* Entries of the hash table are stored as self-type referencing data structures.*/

typedef struct Entries{
    void *data;
    struct Entries* next;
}Entries;

/* Hash table has the size property where the valid indices are from 0 to size-1. All invalid index
    acceses are ignored.
*/
typedef struct hash_table{
    Entries* *Table;
    int size;
    int (*hashing_function)(void *);
}HashTable;

/* Any key is converted to a valid value which is then used to index the hash table. 
In case the index is out of bounds, the function does not achieve its purpose. */

HashTable* newHashTable(int size, int(*hashing_function)(void*));

int addToHashTable(HashTable* table, void* data, void* key); 
//Returns the index at which the data was inserted. Returns -1 if the data was not inserted.

int removeFromHashTable(HashTable* table, void* key, void* data, int (*cmp)(void*, void*)); 
// Removes the element at a particular index which compares equal (cmp returns 0) to the argument data.
// Returns -1 if index is out of bounds. Returns -2 if the element is not found at the index.
// Else returns the index of the deleted element.

Entries* getFirstEntryFromHashTable(HashTable *table, void* key);
// Get the first element of the entries at the index mapped to the key. Helper functions for the 
// enteries are available.

void* getDataFromEntry(Entries* entry);
// Get data of the current entry object. Returns NULL if the entry object is NULL or 
//data in the entry is NULL pointer.

Entries* getNextEntry(Entries *entry);
// Get the next entry object. Returns NULL if the next entry object is NULL or entry object is NULL.