#include "HashTable.h"
#include "Node.h"
#include <stdio.h>
#include "CLI.h"

int main(){
    HashTable* HT = createTable();
    run(HT);
}
    