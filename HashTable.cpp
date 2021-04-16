//
// Created by Ben Worthington on 4/15/21.
//

#include "HashTable.h"

HashTable::HashTable(int size)
{
    Size = size;
    Value = new int[Size];
    Key = new int[Size];

    for (int index=0; index < Size; index++)
    {
        Value[index] = NONE;
        Key[index] = EMPTY;
    }
}

HashTable::HashTable(const HashTable & ht)
{
    Size = ht.Size;
    Value = new int[Size];
    Key = new int[Size];

    for (int index=0; index < Size; index++)
    {
        Value[index] = ht.Value[index];
        Key[index] = ht.Key[index];
    }
}

HashTable::~HashTable()
{
    delete []Value;
    delete []Key;
}

bool HashTable::Insert(int key, int value)
{
    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Key[index] != EMPTY))
        index = Hash2(index);

    // Insert value into hash table
    Value[index] = value;
    Key[index] = key;
    return true;
}

bool HashTable::Search(int key, int &value)
{
    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Key[index] != EMPTY))
        index = Hash2(index);

    // Return value from hash table
    if (Key[index] == key)
        value = Value[index];
    return (Key[index] == key);
}

bool HashTable::Delete(int key)
{
    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Key[index] != EMPTY))
        index = Hash2(index);

    // Delete value from hash table
    if (Key[index] == key)
    {
        Value[index] = NONE;
        Key[index] = DELETED;
        return true;
    }
    return false;
}

int HashTable::Hash(int key)
{
    return key % Size;
}

int HashTable::Hash2(int index)
{
    return (index+1) % Size;
}

void HashTable::Print()
{
    cout << "Index\t" << "Value\t" << "Key\n";
    for (int index=0; index < Size; index++)
        cout << index << "\t"
             << Value[index] << "\t"
             << Key[index] << "\n";
}