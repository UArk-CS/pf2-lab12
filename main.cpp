#include <iostream>
#include "HashTable.h"
using namespace std;

const int MAX = 1000;

int main() {

    srandom(time(nullptr));

    HashTable *ht = new HashTable(20);
    int key, value = 0;

    for (int i = 0; i < 10; i++) {

        key = random() % MAX;
        value = random() % MAX;

        ht->Insert(key, value);

    }

    ht->Print();

    return 0;

}
