#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7

typedef struct HashTable{
    Node* dataMap[SIZE];
}HashTable;

int hash(HashTable* HT, char* key);


void upsert(HashTable* HT, char* name, int value);
HashTable* createTable();
void printAllElements(HashTable* HT);
int get(HashTable* HT, char* key);
void freeHashTable(HashTable* HT);
void removeNode(HashTable* HT, char* key);
void clearTable(HashTable* HT);


#endif