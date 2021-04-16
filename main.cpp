#include <iostream>
#include "HashTable.h"
using namespace std;

int main() {

    srandom(time(nullptr));

    int size, count, max = 0;

    cout << "Enter size of Hash Table: > ";
    cin >> size;
    cout << endl;

    cout << "Enter number of key-value pairs to add: > ";
    cin >> count;
    cout << endl;

    cout << "Enter max value to add: > ";
    cin >> max;
    cout << endl;

    HashTable *ht = new HashTable(size);
    int key, value = 0;

    for (int i = 0; i < count; i++) {

        key = random() % max;
        value = random() % max;

        ht->Insert(key, value);

    }

    ht->Print();

    return 0;

}
