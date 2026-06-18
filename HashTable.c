#include "HashTable.h"

HashTable* createTable(){
    HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
    if(HT == NULL) return NULL;
    for(int i = 0; i <SIZE; i++){
        HT->dataMap[i] = NULL;
    }
    return HT;
}

int Hash(HashTable* HT, char* key){
    int hash = 0;
    int i = 0;
    while(key[i] != '\0'){
        int asciiValue = key[i];
        hash = (hash + asciiValue * 23) % SIZE;
        i++;
    }
    return hash;
}

void upsert(HashTable* HT, char* key, int value){
    int index = Hash(HT,key);
    Node* temp = HT->dataMap[index];
    while(temp != NULL && strcmp(temp->key,key) != 0){
        temp = temp->next;
    }
    if(temp != NULL){
        temp->value = value;
    }
    else{
        Node* newNode = createNode(key, value);
        if(newNode == NULL) return;
        newNode->next = HT->dataMap[index];
        HT->dataMap[index] = newNode;
    }
}

void printAllElements(HashTable* HT){
    if(HT == NULL || HT->dataMap == NULL) return;
    for(int i = 0; i < SIZE; i++){
        Node* temp = HT->dataMap[i];
        while(temp != NULL){
            printf("#%d key:%s value:%d\n",i+1,temp->key,temp->value);
            temp = temp->next;
        }
    }
}

int get(HashTable* HT, char* key){
    if(HT == NULL || key == NULL) return -1;
    int hash_value = Hash(HT,key);
    Node* temp = HT->dataMap[hash_value];
    while(temp != NULL && strcmp(temp->key,key) != 0 ){
        temp = temp->next;
    }
    if(temp != NULL){
        return temp->value;
    }
    return -1;
}

void freeHashTable(HashTable* HT){
    if(HT == NULL) return;
    Node* temp1 = NULL;
    Node* temp2 = NULL;
    for(int i = 0; i < SIZE; i++){
        temp1 = HT->dataMap[i];
        while(temp1 != NULL){
            temp2 = temp1;
            temp1 = temp1->next;
            freeNode(temp2);
        }
    }
    free(HT);
}    

void removeNode(HashTable* HT, char* key){
    if(HT == NULL || key == NULL) return;
    int index = Hash(HT,key);
    Node* temp = HT->dataMap[index];
    if(temp == NULL) return;
    if(strcmp(temp->key,key) == 0){
        HT->dataMap[index] = temp->next;
        freeNode(temp);
        return;
    }
    while(temp->next != NULL && strcmp(temp->next->key,key) != 0){
        temp = temp->next;
    }
    if(temp->next == NULL)return;
    Node* del = temp->next;
    temp->next = temp->next->next;
    freeNode(del);
}
void clearTable(HashTable* HT){
    if(HT == NULL) return;
    Node* temp1 = NULL;
    Node* temp2 = NULL;
    for(int i = 0; i<SIZE; i++){
        temp1 = HT->dataMap[i];
        while(temp1 != NULL){
            temp2 = temp1;
            temp1 = temp1->next;
            freeNode(temp2);
        }
        HT->dataMap[i] = NULL;
    }
}
