//
// Created by Ben Worthington on 4/15/21.
//

#ifndef PF2_LAB12_HASHTABLE_H
#define PF2_LAB12_HASHTABLE_H

#include <iostream>
using namespace std;
const int NONE = 0;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
public:
    // Constructors
    HashTable(int size);
    HashTable(const HashTable & ht);
    ~HashTable();

    // Methods
    bool Insert(int key, int value);
    bool Search(int key, int &value);
    bool Delete(int key);
    void Print();

private:
    // Private methods
    int Hash(int key);
    int Hash2(int index);

    // Private data
    int Size;
    int *Value;
    int *Key;
    int NumOfCollisions;
};

#endif //PF2_LAB12_HASHTABLE_H