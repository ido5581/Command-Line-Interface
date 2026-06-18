#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* createNode(char* key,int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) return NULL;
    newNode->next = NULL;
    newNode->key = strdup(key); 
    if(newNode->key == NULL) {
        free(newNode); 
        return NULL;
    }
    newNode->value = value;
    return newNode;
}

void freeNode(Node* n){
    if(n == NULL) return;
    free(n->key);
    free(n);
    n = NULL;
}