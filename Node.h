#ifndef NODE_H
#define NODE_H

typedef struct Node{
    char* key;
    int value;
    struct Node* next;
}Node;

Node* createNode(char* key, int value);
void freeNode(Node* n);
#endif