#include "hash_table.h"

HashTable* newHashTable(int size, int(*hashing_function)(void*)){

    HashTable* hashTable = malloc(sizeof(HashTable));

    hashTable->size = size;
    hashTable->hashing_function = hashing_function;
    hashTable->Table = calloc(size * sizeof(Entries), 1);

    return hashTable;
}

int addToHashTable(HashTable *hashTable, void *data, void* key){

    int index = hashTable->hashing_function(key);

    if(index < 0 || index >= hashTable->size) return -1; //Failure

    else{

        Entries* newEntry = malloc(sizeof(Entries));
        newEntry->data = data;
        newEntry->next = hashTable->Table[index];
        hashTable->Table[index] = newEntry;
        return index; // Success
    }

}

int removeFromHashTable(HashTable* hashTable, void* key, void* data, int (*cmp)(void*, void*)){

    int index = hashTable->hashing_function(key);

    if(index < 0 || index >= hashTable->size) return -1; //Failure. Index out of bounds.

    else{

        Entries* iterator = hashTable->Table[index];
        Entries *prev = NULL;
        while(iterator && cmp(iterator->data, data)){
            prev = iterator;
            iterator = iterator->next;
        }

        if(iterator){
            if(prev)
            prev->next = iterator->next; //Multiple values for the index.

            else{
                hashTable->Table[index] = iterator->next; // Single value for the index.
            }

            free(iterator);
            return index;
        }

        else return -2; // Failure. Element not found.
    }

}

Entries* getFirstEntryFromHashTable(HashTable *hashTable, void* key){

    int index = hashTable->hashing_function(key);

    if(index < 0 || index >= hashTable->size) return NULL;

    else return hashTable->Table[index];
}

void* getDataFromEntry(Entries* entry){
    return (entry)? entry->data : NULL;
}

Entries* getNextEntry(Entries *entry){
    
    return (entry)? entry->next : NULL;
}

